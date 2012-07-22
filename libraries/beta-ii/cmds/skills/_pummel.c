
#include <std.h>
#include <daemons.h>
#include <damage_types.h>
#include <damage.h>

#define RES "%^RESET%^"
#define COL RES+"%^WHITE%^"
#define COL2 "%^BOLD%^%^BLUE%^"

#define FAIL(s) return notify_fail(s+"\n")

inherit DAEMON;

mixed *pummels = ({
([
  "me" : "You "+COL+"k"+COL2+"n"+COL+"ee"+RES+" $TGT in the gut!",
  "you" : "$TP "+COL+"k"+COL2+"n"+COL+"ee"+COL2+"s"+RES+" you in the gut!",
  "them" : "$TP "+COL+"k"+COL2+"n"+COL+"ee"+COL2+"s"+RES+" $TGT in the gut!",
  "limb" : "torso",
  "dmg" : 1.0
]),
([
  "me" : "You "+COL+"g"+COL2+"ra"+COL+"b"+RES+" $TGT's head and "+
         COL+"sm"+COL2+"a"+COL+"s"+COL2+"h"+RES+" it against your knee!",
  "you" : "$TP "+COL+"g"+COL2+"ra"+COL+"bs"+RES+" your head and "+
          COL+"sm"+COL2+"a"+COL+"sh"+COL2+"es"+RES+" it against $TP_HIS knee!",
  "them" : "$TP "+COL+"g"+COL2+"ra"+COL+"bs"+RES+" $TGT's head and "+
           COL+"sm"+COL2+"a"+COL+"sh"+COL2+"es"+RES+" it against $TP_HIS knee!",
  "limb" : "head",
  "dmg" : 1.2
]),
([
  "me" : "You "+COL2+"e"+COL+"l"+COL2+"b"+COL+"o"+COL2+"w"+RES+
         " $TGT in the "+COL2+"face"+RES+"!",
  "you" : "$TP "+COL2+"e"+COL+"l"+COL2+"b"+COL+"o"+COL2+"w"+COL+"s"+RES+
          " you in the "+COL2+"face"+RES+"!",
  "them" : "$TP "+COL2+"e"+COL+"l"+COL2+"b"+COL+"o"+COL2+"w"+COL+"s"+RES+
           " $TGT in the "+COL2+"face"+RES+"!",
  "limb" : "head",
  "dmg" : 0.9
]),
([
  "me" : "You "+COL+"k"+COL2+"i"+COL+"ck"+RES+" $TGT in the $LIMB!",
  "you" : "$TP "+COL+"k"+COL2+"i"+COL+"ck"+COL2+"s"+RES+" you in the $LIMB!",
  "them" : "$TP "+COL+"k"+COL2+"i"+COL+"ck"+COL2+"s"+RES+" $TGT in the $LIMB!",
  "dmg" : 0.8
]),
([
  "me" : "You "+COL2+"s"+COL+"la"+COL2+"m"+RES+" your fist into $TGT's $LIMB!",
  "you" : "$TP "+COL2+"s"+COL+"la"+COL2+"ms"+RES+" $TP_HIS fist into your $LIMB!",
  "them" : "$TP "+COL2+"s"+COL+"la"+COL2+"ms"+RES+" $TP_HIS fist into $TGT's $LIMB!",
  "dmg" : 1.1
]),
([
  "me" : "You "+COL+"r"+COL2+"a"+COL+"m"+RES+" your fo"+COL2+"rehe"+RES+"ad into $TGT's face!",
  "you" : "$TP "+COL+"r"+COL2+"a"+COL+"ms"+RES+" $TP_HIS fo"+COL2+"rehe"+RES+"ad into your face!",
  "them" : "$TP "+COL+"r"+COL2+"a"+COL+"ms"+RES+" $TP_HIS fo"+COL2+"rehe"+RES+"ad into $TGT's face!",
  "limb" : "head",
  "dmg" : 0.9
]),
([
  "me" : "You whirl and "+COL+"st"+COL2+"rik"+COL+"e"+RES+" $TGT's $LIMB with a quick blow!",
  "you" : "$TP whirl and "+COL+"st"+COL2+"rik"+COL+"es"+RES+" your $LIMB with a quick blow!",
  "them" : "$TP whirls and "+COL+"st"+COL2+"rik"+COL+"es"+RES+" $TGT's $LIMB with a quick blow!",
  "dmg" : 0.8
]),
([
  "me" : "You turn and "+COL2+"dr"+COL+"i"+COL2+"v"+COL+"e"+RES+" your shoulder into $TGT!",
  "you" : "$TP turns and "+COL2+"dr"+COL+"i"+COL2+"v"+COL+"es"+RES+" $TP_HIS shoulder into you!",
  "them" : "$TP turns and "+COL2+"dr"+COL+"i"+COL2+"v"+COL+"es"+RES+" $TP_HIS shoulder into $TGT!",
  "limb" : "torso",
  "dmg" : 1.0
]),
});

int abil() {
  object tp=this_player();
  if (tp && tp->query_subclass() == "berserker" &&
      tp->query_skill("melee") >= 28*6 &&
      tp->query_skill("rage") >= 28*6)
        return 1;
  return 0;
}

string type() { return "attack"; }

void help() {
  message("help",
    "Syntax: <pummel [whom]>\n\n"
    "An unarmed berserker can unleash a series of wild attacks "
    "on an unsuspecting foe.",
    this_player() );
}

int can_cast(object tp, object tgt) {

  if (!tp) return 0;

  if (environment(tp)->query_property("no attack"))
    FAIL("You may not attack here.");

  if (tp->query_disable() || tp->query_casting() || tp->query_magic_round())
    FAIL("You are busy.");

  if (tp->query_ghost())
    FAIL("Your ghostly body passes right through.");

  if (!tgt)
    FAIL("Pummel whom?");

  if (!living(tgt))
    FAIL("You punch it over and over but it doesn't even flinch.");

  if (tgt == tp)
    FAIL("You punch yourself in the face. Good going.");

  if (sizeof(tp->query_wielded()))
    FAIL("You need your hands free first!");

  if (!tp->kill_ob(tgt))
    FAIL("You may not attack "+tgt->query_cap_name()+".");
  
  return 1;
}

int cmd_pummel(string str) {
  object tp=this_player();
  object env=environment(tp);
  object tgt;
  int num, maxrank;
  
  if (!abil()) return 0;

  if (str)
    tgt = present(str, env);
  else
    tgt = tp->query_current_attacker();

  if (!can_cast(tp, tgt)) return 0;

  maxrank = tp->query_level()/15;
  if (maxrank < 1) maxrank = 1;
  if (maxrank > 4) maxrank = 4;
  
  num = 1;
  if (random(100) < 20) num += 1;
  num += (tp->query_skill("rage")-6*22)/(6*8);
  if (num > 5) num = 5 + (num-5)/1.5;

  for (int i=num; i > 0; i--) {

    int dmg, rank, cost;
    int pum, div;
    string limb=tgt->return_limb();
    string mymsg, yourmsg, theirmsg;

    rank = random(maxrank)+1;
    pum = random(sizeof(pummels));

    dmg = BALANCE3_D->get_damage(tp, tgt, rank,
      ({"melee", "melee", "attack", "rage", "ferocity"}),
      ({"strength","dexterity"}),
      ({"strength","dexterity"}) );
    div = num;
    if (num > 2)
      div -= 1;
    if (div < 1) div = 1;
    dmg /= div;
    dmg *= pummels[pum]["dmg"];

    cost = BALANCE3_D->get_cost(dmg, rank, "sp");

    if (tp->query_sp() < cost) {
      if (i==num)
        FAIL("You are too tired.");
      else
        message("combat", "You run out of stamina.", tp);
    }

    tp->add_sp(-cost);
    tp->set_disable();
    
    if (pummels[pum][limb])
      limb = pummels[pum]["limb"];

    mymsg = pummels[pum]["me"];
    mymsg = replace_string(mymsg, "$TGT", tgt->query_cap_name());
    mymsg = replace_string(mymsg, "$LIMB", limb);
    yourmsg = pummels[pum]["you"];
    yourmsg = replace_string(yourmsg, "$TP_HIS", tp->query_possessive());
    yourmsg = replace_string(yourmsg, "$TP", tp->query_cap_name());
    yourmsg = replace_string(yourmsg, "$LIMB", limb);
    theirmsg = pummels[pum]["them"];
    theirmsg = replace_string(theirmsg, "$TGT", tgt->query_cap_name());
    theirmsg = replace_string(theirmsg, "$TP_HIS", tp->query_possessive());
    theirmsg = replace_string(theirmsg, "$TP", tp->query_cap_name());
    theirmsg = replace_string(theirmsg, "$LIMB", limb);

    message("combat", mymsg, tp);
    message("combat", yourmsg, tgt);
    message("combat", theirmsg, env, ({tp, tgt}) );
    
    tgt->do_damage(limb, dmg, tp->query_unarmed_damage_type(), tp->query_unarmed_damage_flags(), tp);
    tp->add_skill_points("melee", dmg/15);
  }

  return 1;
}

