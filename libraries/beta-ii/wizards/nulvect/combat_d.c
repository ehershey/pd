
#include <std.h>
#include <daemons.h>
#include <damage.h>
#include <damage_types.h>

#define MAX_MELEE_WC        15
#define MAX_ATTACK_BONUS    3
//Normal Damage Message Color
#define ATTCL "%^RED%^"
//Missed Attack Message Color
#define MISSCL "%^GREEN%^"
//High Damage Message Color
#define HIATTCL "%^BOLD%^%^CYAN%^"

#define NO_COMBAT_ROUNDS_WHEN_BUSY 1

inherit DAEMON;

mapping skillmods;
mapping max_num_attacks;
mapping hit_verbs, hit_adverbs;
string *miss_msgs;
int expmod;

void do_combat_rounds(object);
varargs int query_combat_rounds(object, object *);
static void combat_round_weapon(object, object);
static void combat_round_melee(object, object);
static void combat_round_magic(object, object);
static void increase_skills(object, int, string *);
static int calc_sight_adj(object, object);
string query_melee_limb(object tp, int ref);
static void hit_messages(object, object, string, string, int, int);
static void miss_messages(object, object, int);
static string replace_macros(string, object);

void create() {
  ::create();

  // the mods are percentages of damage done / taken

  // exp given for doing or taking damage
  expmod = 50;

  // skill points given
  skillmods = ([
    "attack" : 50,
    "defense" : 25, // defense is for damage taken
    "melee" : 50,
    "double wielding" : 50,
    "axe" : 50,
    "blade" : 50,
    "blunt" : 50,
    "flail" : 60,
    "knife" : 50,
    "projectile" : 50,
    "ranged" : 30,
    "magic defense" : 35, // for damage taken
    "faith" : 50,
    "default" : 70, // catch-all for magic
  ]);

  max_num_attacks = ([
    "fighter" : 8,
    "mage" : 4,
    "clergy" : 5,
    "monk" : 6,
    "cleric" : 4,
    "rogue" : 6,
    "scout" : 7,
    "wanderer" : 6,
    "elementalist" : 5,
    "dragon" : 6,
    "red" : 7,
    "vampire" : 8,
    "child" : 5,
    "default" : 6, // intended for mobs with no class/sub set
  ]);

  hit_verbs = ([
    "blunt" : ({
      "tap", "tickle", "sting", "hurt", "strike", "strike",
      "send", "knock", "slam", "blast", "destroy", "destroy",
    }),
    "slash" : ({
      "tap", "tickle", "sting", "graze", "cut", "slice",
      "slice", "shear", "strike", "mutilate", "dismember", "destroy",
    }),
    "pierce" : ({
      "tap", "tickle", "sting", "graze", "cut", "jab",
      "stab", "stab", "pierce", "puncture", "shank", "destroy",
    }),
  ]);

  hit_adverbs = ([
    "blunt" : ({
      "innocently", "lightly", 0, "mildly", "badly", 0,
      "a bone crushing blow", 0, "mercilessly", "powerfully", 0, "utterly",
    }),
    "slash" : ({
      0, 0, "sharply", 0, 0, 0,
      "horribly", "to pieces", "letting blood", 0, 0, "utterly"
    }),
    "pierce" : ({
      0, 0, 0, 0, "badly", 0,
      0, "deeply", "letting blood", "severely", 0, "utterly",
    }),
  ]);

  miss_msgs = ({
    "You miss.",
    "You swing, and miss!",
    "$N sidesteps your poorly planned attack.",
    "You decide to daydream a moment instead of attack.",
    "You are too slow this time!",
    "$N dances around as you miss.",
    "$N never knew what missed $O.",
    "$N dodges your inept attack.",
  });
}

void do_combat_rounds(object tp) {
  object tgt;
  int casting;

  if (!tp) return;

  tgt = tp->query_current_attacker();
  if (!tgt) return;

  if (!tgt->query_is_attacker(tp))
    tgt->add_attacker(tp);

  if (tp->query_rest_type())
    return;

  if (tp->is_monster() && tp->query_spell_chance() > random(100)) {
    string spell = tp->get_random_spell();
    if (spell)
      tp->force_me(spell);
  }

#ifdef NO_COMBAT_ROUNDS_WHEN_BUSY
  if (tp->query_busy())
    return;
#endif

  casting = tp->query_casting();

  if (tp->query_magic_round() && !casting)
    return;

  if (casting)
    combat_round_magic(tp, tgt);
  else if (sizeof(tp->query_wielded()))
    combat_round_weapon(tp, tgt);
  else
    combat_round_melee(tp, tgt);

}

varargs int query_combat_rounds(object tp, object *weapons) {
  int num_attacks;
  int max;

  if (!tp) return 0;

  if (nullp(weapons))
    weapons = distinct_array(tp->query_wielded());

  num_attacks = sizeof(weapons);
  // melee:
  if (!num_attacks) {
    num_attacks = 1;
    if (random(100) > 160 - tp->query_skill("attack"))
      num_attacks++;
    if (tp->query_race() == "raknid")
      num_attacks = 2 * num_attacks;
    if (random(2000) < 400)
      num_attacks++;
  }

  num_attacks += tp->query_skill("attack")/(random(50)+100);

  // check subclass first, then class, the "none" is a safety for mobs
  max = max_num_attacks[tp->query_subclass() || "none"] ||
        max_num_attacks[tp->query_class() || "none"] ||
        max_num_attacks["default"];

  num_attacks += tp->query_combat_round_bonus();

  if (num_attacks > max)
    num_attacks = max;

  if (num_attacks < 1 && random(1000) < 700)
    num_attacks = 1;

  return num_attacks;
}

static void combat_round_weapon(object tp, object tgt) {
  object *weapons, *dwpenalty;
  string *skills;
  int num_attacks;
  int hit, dodge, dw, mult;
  
  weapons = distinct_array(tp->query_wielded());
  num_attacks = query_combat_rounds(tp, weapons);

  // you can wield 1 weapon without penalty with 2 hands,
  // or 2 weapons in 4 hands, 3 weapons in 6, etc
  // this means the double wielding skill only applies to the
  //   third and fourth weapons for raknids
  mult = sizeof(weapons);
  mult -= sizeof(tp->query_wielding_limbs())/2;
  if (mult < 0)
    mult = 0;

  // these weapons will be harder to hit with if dw is too low
  dwpenalty = weapons[ 0 .. <(mult+1) ];

  dw = tp->query_skill("double wielding");

  hit = tp->query_stats("dexterity");
#ifdef NO_COMBAT_ROUNDS_WHEN_BUSY
  // the +50 is so players can hit mobs - players carry lots of stuff and
  // mobs carry almost nothing
  // this means mobs will have a very easy time hitting players as well
  hit += 50;
#endif
  // this is 1/4 of how much weight you're carrying (as a percentage of max)
  hit -= (tp->query_internal_encumbrance() * 100 /
          tp->query_max_internal_encumbrance()) / 4;

  dodge = tgt->query_stats("dexterity");
  dodge -= (tgt->query_internal_encumbrance() * 100 /
            tgt->query_max_internal_encumbrance()) / 4;

  hit -= dodge;

  skills = ({ "attack" });
  if (mult)
    skills += ({ "double wielding" });

  for (int i = 0; i < num_attacks; i++) {
    string limb = tgt->return_target_limb();
    string weptype, wepname;
    object wep;
    int hitmod, tmp, poison, damage, actual;
    int damtype, damflags;
    mixed wepspecial;

    // ensures each weapon gets 1 swing, then any extra swings use a random weapon
    if (i >= sizeof(weapons))
      wep = weapons[random(sizeof(weapons))];
    else
      wep = weapons[i];

    weptype = wep->query_type();
    wepname = wep->query_name();
    damtype = wep->query_damage_type();
    damflags = wep->query_damage_flags();

    hitmod = 0;

    // double wielding penalty for hit
    if (mult && member_array(wep, dwpenalty) != -1) {
      tmp = 30+random(90) - dw;
      if (tmp < 0)
        hitmod += tmp;
    }

    if (tp->query_blind())
      hitmod -= hit * (1 + random(3)) / 5; // 1/5th to 3/5ths less hit chance

    if (hit+hitmod < random(60) + 20) {
      miss_messages(tp, tgt, damtype);
      continue;
    }

    damage = tp->query_skill(wep->query_type());
#ifdef NO_COMBAT_ROUNDS_WHEN_BUSY
    damage = damage * wep->query_hands() / (6 + random(2));
#else
    damage = damage * wep->query_hands() / 9;
#endif
    damage += tp->query_stats("strength") / (2 + random(3));

    // double wielding penalty for damage
    if (mult) {
      if (member_array(wep, dwpenalty) != -1 && random(200) > dw)
        damage = damage * 60 / 100;
      else
        damage = damage * 80 / 100;
    }

#ifdef NO_COMBAT_ROUNDS_WHEN_BUSY
    damage += wep->query_wc()+1 * 2;
#else
    damage += wep->query_wc() + 2;
#endif
    damage /= 2;
    damage += random(damage);
    damage += tp->query_skill("attack")*MAX_ATTACK_BONUS/100;
    
    wepspecial = wep->query_hit();
    if (functionp(wepspecial))
      damage += evaluate(wepspecial, tgt)*2/3;

    damage += random(tp->query_sp())/10;

    if (damage > 5 && tp->is_player())
      tp->add_sp(-1);

    damage += tp->query_physical()*3;
    damage -= calc_sight_adj(tp, tgt);

    actual = tgt->do_damage(limb, damage, damtype, damflags, tp); 

    poison = wep->query_poisoning();
    if (poison > random(40) && actual >= 5) {
      poison = random(poison+1);
      tgt->add_poisoning(poison);
      wep->add_poisoning(-poison);
    }

    hit_messages(tp, tgt, limb, wepname, damtype, actual);

    increase_skills(tp, actual, skills + ({ weptype }) );
    increase_skills(tgt, actual, ({ "defense" }) );

  }
}

static void combat_round_melee(object tp, object tgt) {
  int num_attacks;
  int damtype, damflags;
  mapping info;

  num_attacks = query_combat_rounds(tp, 0 );

  info = tp->query_melee_info();
  damtype = info["type"];
  damflags = info["flags"];

  for (int i = 0; i < num_attacks; i++) {
    string limb = tgt->return_target_limb();
    string mylimb;
    int hit, dodge, damage, actual;
    int reduce;

    hit = tp->query_stats("dexterity") + 35;
#ifdef NO_COMBAT_ROUNDS_WHEN_BUSY
    hit += 25;
#endif
    // this is 1/3rd of how much weight you're carrying (as a percentage of max)
    hit -= (tp->query_internal_encumbrance() * 100 /
            tp->query_max_internal_encumbrance()) / 3;
    
    dodge = tgt->query_stats("dexterity") - 35;
    dodge -= (tgt->query_internal_encumbrance() * 100 /
              tgt->query_max_internal_encumbrance()) / 3;

    if (dodge < -50) dodge = -50;
    if (dodge > 0) dodge = 0;

    hit -= dodge;

    if (tp->query_blind())
      hit = hit * (3 + random(3)) / 5; // 3/5ths, 4/5ths, or normal hit chance

    if (hit < random(60) + 20) {
      miss_messages(tp, tgt, damtype);
      continue;
    }

    damage = tp->query_skill("melee")*MAX_MELEE_WC/100 +
             tp->query_skill("attack")*MAX_ATTACK_BONUS/100 + 2;
#ifdef NO_COMBAT_ROUNDS_WHEN_BUSY
    damage = damage/2;
    damage += random(damage);
#else
    damage = random(damage);
#endif
    damage += random(tp->query_sp())/10;
    damage += tp->query_stats("strength") / (2 + random(3) );

    if (damage > 5)
      tp->add_sp(-1);

#ifdef NO_COMBAT_ROUNDS_WHEN_BUSY
    damage += tp->query_physical()*(3+random(5));
#else
    damage += tp->query_physical()*3;
#endif
    damage -= calc_sight_adj(tp, tgt);

    // 'reduce' will be set to 0 or 1 by the query_melee_limb function
    mylimb = query_melee_limb(tp, ref reduce);

    if (reduce)
      damage = damage*(60+random(20))/100;

    actual = tgt->do_damage(limb, damage, damtype, damflags, tp); 

    hit_messages(tp, tgt, limb, mylimb, damtype, actual);

    increase_skills(tp, actual, ({ "attack", "melee" }) );
    increase_skills(tgt, actual, ({ "defense" }) );
  }

}

static void combat_round_magic(object tp, object tgt) {
  string limb = tgt->return_target_limb();
  int hit, damage, actual;
  int damtype, damflags;
  mapping info;

  hit = tp->query_stats("intelligence")*3;
  hit -= tgt->query_stats("wisdom") - 70;

  info = tp->query_casting_info();

  damtype = info["type"];
  damflags = info["flags"];

  if (tp->query_blind())
    hit = hit * (2+random(4)) / 5; // 2/5ths, 3/5ths, 4/5ths, or normal hit chance

  if (hit < random(60) + 20) {
    miss_messages(tp, tgt, damtype);
  }
  else {

    damage = info["damage"] || tp->query_casting();

    damage += tp->query_spiritual()*3;
    damage -= calc_sight_adj(tp, tgt);

    actual = tgt->do_damage(limb, damage, damtype, damflags, tp); 

    hit_messages(tp, tgt, limb, "magic", damtype, actual);

    increase_skills(tp, actual, info["skills"] || ({ "magic attack" }) );
    increase_skills(tgt, actual, info["defskills"] || ({ "magic defense" }) );
  }

  tp->set_casting(0);
  tp->remove_casting_info();
}

static void increase_skills(object tp, int damage, string *skills) {

  if (damage > 0)
    foreach (string skill in skills)
      tp->add_skill_points(skill,
        damage * (skillmods[skill] || skillmods["default"]) / 100 );

  else
    foreach (string skill in skills)
      tp->add_skill_points(skill, 1);

  if (damage > 500)
    tp->add_exp(random(500));
  else
    tp->add_exp(damage * expmod / 100);

}

static int calc_sight_adj(object tp, object tgt) {
  int elight, ret;

  ret = 0;
  elight = effective_light(tp);
  if (elight > 6 || elight < 1)
    ret = random(25);
  if (tgt && tgt->query_invis()) {
    ret += 65 / (1+random(tp->query_skill("perception")/3));
    tgt->add_sp(-ret);
  }
  if (tp->query_blind()) ret += 5+random(40);
  return ret;
}

string query_melee_limb(object tp, int ref reduce) {
  string *mylimbs, *severed, *pri, *sec;
  string prifilt, secfilt;

  mylimbs = tp->query_limbs();
  if (sizeof(mylimbs) == 1)
    return mylimbs[0];

  reduce = 1;

  // extra limbs we should look for and use in melee
  prifilt = "tail|horn";
  secfilt = "head";

  // race specific extra limbs:
  switch (tp->query_race()) {
    case "dragon":
      prifilt += "|wing";
    break;
    case "archangel": case "demon":
      secfilt += "|wing";
    break;
  }

  severed = tp->query_severed_limbs();

  // pri are primary attack limbs - hands and feet for most
  pri = ({});
  pri |= tp->query_wielding_limbs();
  pri |= tp->query_walking_limbs();
  pri |= regexp(mylimbs, prifilt);
  pri -= severed;

  // sec are secondary attack limbs - arms and legs, head, etc
  sec = filter(mylimbs - pri, (:
    member_array($(tp)->query_reference($1), $(pri)) != -1
  :) );
  sec |= regexp(mylimbs, secfilt);
  sec -= pri;
  sec -= severed;

  if ((!sizeof(pri) || random(100) < 25) && sizeof(sec))
    return sec[random(sizeof(sec))];

  if (!sizeof(pri))
    return mylimbs[random(sizeof(mylimbs))];

  reduce = 0;
  return pri[random(sizeof(pri))];
}

static void hit_messages(object tp, object tgt, string limb, string instrument, int type, int damage) {
  string tpname, tgtname;
  string me, you, others, high;
  string verb, adverb, verbtype;
  string *verbtypes;
  int i, blunt, slash, pierce;

  tpname = tp->query_cap_name();
  tgtname = tgt->query_cap_name();

  if (tp->query_level() > 20)
    i = damage/(tp->query_level()/4);
  else
    i = damage/4;

  if (i > 10)
    high = "_high";
  else
    high = "";

  if (damage < 1) {
    me = "You hit "+tgtname+" ineffectively in the "+limb+".";
    you = tpname+" hits you ineffectively in the "+limb+".";
    others = tpname+" hits "+tgtname+" ineffectively in the "+limb+".";
  }
  else {
    verbtypes = ({});
    if (type & DAMAGE_BLUNT) verbtypes += ({ "blunt" });
    if (type & DAMAGE_SLASH) verbtypes += ({ "slash" });
    if (type & DAMAGE_PIERCE) verbtypes += ({ "pierce" });

    verbtype = verbtypes[random(sizeof(verbtypes))];
    verb = hit_verbs[verbtype][i];
    adverb = hit_adverbs[verbtype][i];
    if (!adverb)
      adverb = "";
    else
      adverb += " ";

    me = sprintf("You %s %s %sin the %s with your %s.",
      verb, tgtname, adverb, limb, instrument);

    you = sprintf("%s %ss you %sin the %s with %s %s.",
      tpname, verb, adverb, limb, tp->query_possessive(), instrument);

    others = sprintf("%s %ss %s %sin the %s with %s %s.",
      tpname, verb, tgtname, adverb, limb,
      tp->query_possessive(), instrument);
  }

  message("my_combat"+high, me, tp);
  message("my_combat"+high, you, tgt);
  message("other_combat"+high, others, environment(tp), ({ tp, tgt }));

}

static void miss_messages(object tp, object tgt, int type) {
  string mymsg, yourmsg, theirmsg;

  if (!tp || !tgt) return;

  if (type & DAMAGE_PHYSICAL) {
    mymsg = miss_msgs[random(sizeof(miss_msgs))];
    mymsg = replace_macros(mymsg, tgt);
    yourmsg = tp->query_cap_name()+" missed you.";
    theirmsg = tp->query_cap_name()+" misses "+tp->query_possessive()+
      " attack on "+tgt->query_cap_name()+".";
  }
  else {
    mymsg = "Your magic powers fail you.";
    yourmsg = tp->query_cap_name()+"'s magic powers fail in an attack on you.";
    theirmsg = tp->query_cap_name()+"'s magic powers fail in an attack "
      "on "+tgt->query_cap_name()+".";
  }

  message("my_combat_miss", mymsg, tp);
  message("my_combat_miss", yourmsg, tgt);
  message("other_combat_miss", theirmsg, environment(tp), ({ tp, tgt }) );
}

static string replace_macros(string str, object who) {
  str = replace_string(str, "$N", who->query_cap_name());
  str = replace_string(str, "$O", who->query_objective());
  return str;
}
