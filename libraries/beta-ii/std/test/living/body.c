//      /std/living/body.c
//      from the Nightmare mudlib
//      the code for the limbs system used by the Nightmare mudlib
//      based on the TMI LOS system by Brian with help from Buddha
//      written by Descartes of Borg september 1992

#include <std.h>
#include <daemons.h>
#include <objects.h>
#include <limb_status.h>

inherit CONTAINER;

mixed *deaths;
mapping severed, body;
static mapping wielded;
static string target_limb;
string *limbs;
int all_my_fingers;
static int num_wielded;

string *query_walking_limbs();
int query_mobile();
int query_limb_status(string limb);
int query_usable(string limb);
int query_useable(string limb);
string *query_limbs_wielded();
void set_wielding_limbs(string *str);
int check_on_limb(string limb);
string *query_wielding_limbs();
string type_ok(string type, string limb);
void init_limb_data();
void set_fingers(int x);
int query_fingers();
void set_overall_ac(int ac);
void set_ac(string limb_name, int ac);
int add_limb(string limb_name, string limb_ref, int max_dam, int curr_dam, int limb_ac);
int remove_limb(string limb_name);
int query_ac(string limb_name);
int do_damage(string limb_name, int damage);
string query_reference(string limb);
string equip_weapon_to_limb(object weap, string limb);
string equip_armour_to_limb(object arm, string *limb);
object query_weapon(string limb);
string *query_armour(string limb);
object *query_armour_ob(string limb);
int remove_armour_from_limb(object arm, string *limb);
int remove_weapon_from_limb(object ob);
string *query_limbs();
string return_limb();
string return_target_limb();
int query_is_limb(string limb);

void create() {
  container::create();
}

//  This function initializes the variables
//  This should only be called when there is NO limb data yet
mapping query_body_mapping() { return body; }
void init_limb_data() {
    body = ([]);
    limbs = ({});
    wielded = ([]);
    severed = ([]);
}


//  This function is only for lazy wizzes to use when creating monsters!!

void set_overall_ac(int x) {
    int i;

    for(i=0; i<sizeof(limbs); i++) {
        if(limbs[i] != "torso") set_ac(limbs[i], x);
        else set_ac("torso", (2*x));
    }
}

void set_ac(string limb_name, int ac) {
    body[limb_name]["ac"] = ac;
}


//  This function adds limbs to a player or monster
//  The values passed to it mean the following:
//  limb_name: The name of the limb being added
//  limb_ref: The name of other limbs that should be lost when this
//      limb is lost, or FATAL is losing it is fatal, or "" if nothing
//      else should happen.
//  max_dam:  The maximum damage the limb can take before being lost
//  curr_dam:  How much damage has been done to the limb thus far.  This
//      allows you to create wounded monsters.
//  limb_ac:  How much protection the limb has.  By setting it to >0, you
//      set it's natural ac
//  NOTE:  In order to make a creature with 4 arms, each arm must have a
//      distinctive name, like "lower right arm", "right arm", "lower left
//      arm", "lower right arm"

int add_limb(string limb_name, string limb_ref, int max_dam, int curr_dam, int limb_ac) {
    body[limb_name] = ([ "limb_ref": limb_ref, "max_dam": max_dam, "damage": curr_dam, "ac": limb_ac ]);
    if(!limbs) limbs = ({});
    limbs += ({ limb_name });
    body[limb_name]["armour"] = ({});
    body[limb_name]["armour_ob"] = ({});
    body[limb_name]["weapons"] = 0;
    if(!severed) return 1;
    if(severed[limb_name]) map_delete(severed, limb_name);
    return 1;
}

void augment_body(int x) {
    int tmp;
    int i;
    string b_type;
    
  
     if((string)this_object()->query_race() == "satyr" ||
        (string)this_object()->query_race() == "centaur") {
        if(member_array("left foot", limbs) != -1) {
          remove_limb("left foot");
          map_delete(severed, "left foot");
        }
        if(member_array("right foot", limbs) != -1) {
          remove_limb("right foot");
          map_delete(severed, "right foot");
        }
        if(severed && severed["left foot"])
          map_delete(severed, "left foot");
        if(severed && severed["right foot"])
          map_delete(severed, "right foot");
    }

    b_type = this_object()->query_body_type();
    if(b_type)  
    {
      for(i=0, tmp = sizeof(limbs); i<tmp; i++)
        body[limbs[i]]["max_dam"] =
 this_object()->query_max_hp()/((int)RACE_D->query_max_mon_dam(limbs[i],b_type)*5);
      return;
    } else
    for(i=0, tmp = sizeof(limbs); i<tmp; i++)
      {
       if (!limbs[i]||limbs[i]=="") continue;
      body[limbs[i]]["max_dam"] =
       (this_object()->query_max_hp()/RACE_D->query_max_dam(limbs[i], this_object()->query_race()))*5;

      }

}

//  This function removes a limb

int remove_limb(string limb_name) {
    if(body[limb_name]) {
        severed[limb_name] = body[limb_name]["limb_ref"];
        map_delete(body, limb_name);
        limbs -= ({ limb_name });
        return 1;
    }
    return 0;
}

//  This function returns a random limb

string return_limb() {
    return limbs[random(sizeof(limbs))];
}

//  This function returns a random limb, giving weight to
//  those limbs that can take the most damage

string return_target_limb() {
    string tmp_lmb;
    int res, i, count;

    if(target_limb && !query_is_limb(target_limb)) target_limb = 0;
    if(target_limb) {
        tmp_lmb = target_limb;
        target_limb = 0;
        if(random(120) > (int)this_object()->query_skill("defense"))
          return tmp_lmb;
    }
    count = member_array("torso", limbs);
    i = 0;
    while(i++ < ((sizeof(limbs))/2))
      if( (res=random(sizeof(limbs))) == count ) break;
    return limbs[res];
}

string *query_limbs() { return limbs; }

int query_is_limb(string limb) {
    if(member_array(limb, limbs) != -1) return 1;
    else return 0;
}

string *query_walking_limbs() {
  object to = this_object();
  string r;
  string *l = ({});
  string *mylimbs = ({});
  string *attached = ({});

  if (userp(to))
    r = to->query_race();
  else
    r = to->query_body_type();

  if (!r)
    return ({});

  // note that checking this_object()->query_limbs() only returns the limbs
  // you have right at this moment, so if your foot was cut off it wouldn't
  // show up in that list
  // we ask RACE_D what limbs this race should have

  if (RACE_D->is_race(r))
    mylimbs = RACE_D->query_limbs(r);
  else if (RACE_D->is_monster_race(r))
    mylimbs = keys(RACE_D->monster_body(r));
  else
    return ({});

  switch (r) {
    case "bastet":
      l = ({ "left rear paw", "right rear paw" });
    break;
    case "centaur":
      l = ({ "left fore hoof", "right fore hoof",
             "left rear hoof", "right rear hoof" });
    break;
    case "dragon":
      l = ({ "front left claw", "front right claw",
             "back left claw", "back right claw" });
    break;
    case "minotaur":
      l = ({ "left hoof", "right hoof" });
    break;
    case "raknid":
      l = ({ "right foreleg", "left foreleg",
             "right rear leg", "left rear leg" });
    break;
    case "weimic":
      l = ({ "left front claw", "right front claw",
             "left rear claw", "right rear claw"});
    break;

    default:
      l = regexp(mylimbs, "foot|paw|hoof|claw");
      if (!sizeof(l))
        l = regexp(mylimbs, "leg");
  }

  if (!sizeof(l)) return mylimbs;

  foreach (string limb in filter(mylimbs, (: !regexp($1, "torso|body|abdomen|head") :) )) {
    string refl;
    if (refl = to->query_reference(limb) &&
        member_array(refl, l) != -1 &&
        member_array(limb, attached) == -1)
          attached += ({ limb });
  }

  l += attached;

  return l;
}

int query_mobile() {
  object to = this_object();
  string *walk = to->query_walking_limbs();
  string *sev = filter(walk, (: $(to)->query_useable($1) == 0 :) );
  // if > 40% of walking limbs are not useable, we are not mobile
  return sizeof(sev)*100/sizeof(walk) < 40;
}

int query_limb_status(string limb) {
  int ret = 0;
  if (!limb || !query_is_limb(limb))
    return LIMB_ERROR;
  if (member_array(limb, this_object()->query_wielding_limbs()) != -1)
    ret |= LIMB_WIELDABLE;
  if (member_array(limb, this_object()->query_limbs_wielded()) != -1)
    ret |= LIMB_WIELDING;
  if (sizeof(this_object()->query_armour_ob(limb)))
    ret |= LIMB_WEARING;
  if (member_array(limb, this_object()->query_severed_limbs()) != -1)
    ret |= LIMB_SEVERED;
  if (this_object()->query_crippled(limb))
    ret |= LIMB_CRIPPLED;
  return ret;
}

int query_usable(string limb) { return query_useable(limb); }
int query_useable(string limb) {
  int s = query_limb_status(limb);
  if (s & LIMB_ERROR || s & LIMB_SEVERED || s & LIMB_CRIPPLED)
    return 0;
  return 1;
}


int query_max_dam(string limb) {
    if(body[limb]) return body[limb]["max_dam"];
}

int query_dam(string limb) {
    if(body[limb]) return body[limb]["damage"];
}

string query_reference(string limb) {
    if(body[limb]) return body[limb]["limb_ref"];
}

int damage(int x, string *str)
{
 string bod;
 int ret;

 bod = return_target_limb();
 ret = do_damage(bod, x);
 check_on_limb(bod);
 return ret;
}

int do_damage(string limb, int damage) {
  object to = this_object();
    // reduce damage for players
      if (to->is_player()) damage = damage/2;

    // AC damage reduction
      damage = damage - to->query_current_protection(limb);
      if(damage <= 0)
        return 0;

    if(body[limb]) {
        if(userp(to))
            body[limb]["damage"] += damage/3;
        else
            body[limb]["damage"] += damage/(to->query_level() * 3);
        to->add_hp(-damage);
        if(body[limb]["damage"] < 0) body[limb]["damage"] = 0;
        check_on_limb(limb);
        if (to->query_max_hp() < to->query_hp()) to->set_hp(to->query_max_hp());
        this_object()->show_status_line();
        return damage;
    }
     to->show_status_line();

    return damage;
}

int do_direct_damage(string limb, int damage) {
  object to = this_object();
    //halve the pvp damage
      if(this_player()->is_player() && to->is_player()) damage = damage/2;

    if(body[limb]) {
        if(userp(to))
            body[limb]["damage"] += damage/3;
        else
            body[limb]["damage"] += damage/(to->query_level() * 3);
        to->add_hp(-damage);
        if(body[limb]["damage"] < 0) body[limb]["damage"] = 0;
        check_on_limb(limb);
        if (to->query_max_hp() < to->query_hp()) to->set_hp(to->query_max_hp());
        to->show_status_line();
        return damage;
    }
     to->show_status_line();

    return damage;
}

int query_ac(string limb) {
    int tmp_ac, i;

    if(!body) return 0;
    if(!body[limb]) return 0;
    tmp_ac = 0;
    i = sizeof(body[limb]["armour_ob"]);
    while(i--)
      tmp_ac += (body[limb]["armour_ob"][i] ? (int)body[limb]["armour_ob"][i]->query_ac() : 0);
    return tmp_ac;
}

void remove_wielding_limb(string str) {
  if (member_array(str, limbs) == -1) return;
  body[str]["wieldable"] = 0;
}

string equip_weapon_to_limb(object weap, string limb) {
  string *ls;
  limb=replace_string(limb, ", ", ",");
  limb=replace_string(limb, " ,", ",");
  ls=explode(limb,",");
  foreach (string limb1 in ls) {
    if(member_array(limb1, limbs) == -1)
        return "You have no "+limb1+"!";
    if(wielded[limb1]) return "You are already wielding something in your "+limb1+"!\n";
    if(member_array("shield", body[limb1]["armour"]) != -1)
      return "You cannot wield a weapon while wearing a shield in your "+limb1+".\n";
    if(!body[limb1]["wieldable"])
        return "You cannot wield a weapon with a "+limb1+"!\n";

    body[limb1]["ac"] += (int)weap->query_ac();
    body[limb1]["weapons"] = weap;
    wielded[limb1] = weap;
  }
  num_wielded++;
  return 0;
}

string equip_armour_to_limb(object arm, string *limb) {
    int i;
    function f;
    string y, type;

    type = (string)arm->query_type();
    i = sizeof(limb);
    while(i--) if(y=type_ok(type, limb[i])) return y;
//    if(functionp(f = (mixed)arm->query_wear()) && !((*f)())) return "NO";
    i = sizeof(limb);
    while(i--) {
        body[limb[i]]["ac"] += (int)arm->query_ac();
        body[limb[i]]["armour"] += ({type});
        body[limb[i]]["armour_ob"] += ({ arm });
    }
    return 0;
}

string type_ok(string type, string limb) {
    int worn, x, i;

    if(!body[limb]) return "You have no "+limb+"!";
    if(member_array(type, body[limb]["armour"]) != -1) worn = 1;
    else worn = 0;
    switch(type) {
        case "shield":
            if(worn) return "You are already wearing a shield!\n";
            else if(wielded[limb])
              return "You cannot wear a shield while you are wielding a weapon in your "+limb+".\n";
            else return 0;
            break;
        case "body armour":
            if(member_array("armour", body[limb]["armour"]) != -1)
              return "You cannot wear regular armour with body armour.\n";
            else if(worn) return "You are already wearing body armour!\n";
            else return 0;
            break;
        case "ring":
            i = 0;
            x = sizeof(body[limb]["armour"]);
            while(x--) 
                if(body[limb]["armour"][x] == "ring") i++;
            if(i >= all_my_fingers)
              return "You do not have that many fingers on your "+limb+".";
            else return 0;
            break;
        case "armour":
            if(member_array("body armour", body[limb]["armour"]) != -1)
              return "You may not wear body armour and armour at the same time.\n";
            else if(worn) return "You may only wear one piece of body armour at a time.\n";
            else return 0;
            break;
        default:
            if(worn) return "You may only wear one armour of type "+type+" at a time.\n";
            else return 0;
            break;
    }
    return "Error in wearing armour.\n";
}

string *query_armour(string limb) {
    if(body[limb]) return body[limb]["armour"];
    else return 0;
}

object *query_armour_ob(string limb) {
    if(body[limb]) return body[limb]["armour_ob"];
    else return 0;
}

int remove_weapon_from_limb(object ob) {
    int i;
    string *ind;

    ind = keys(wielded);
    for(i=0; i<sizeof(ind); i++) {
        if(wielded[ind[i]] == ob) {
            map_delete(wielded, ind[i]);
            if(body[ind[i]]) {
               body[ind[i]]["armour"] -= ({ "weapon" });
               body[ind[i]]["armour_ob"] -= ({ ob });
               body[ind[i]]["weapons"] = 0;
            } else CHAT_D->do_raw_chat("system", "Error <system> Error occured in remove_weapon_from_limb() in body.c:  "+file_name(this_object()));
        }
    }
    num_wielded --;
    return 1;
}

int remove_armour_from_limb(object arm, string *limb) {
    int i, arm_class;
    string type;

    arm_class = (int)arm->query_ac();
    type = (string)arm->query_type();
    for(i=0; i<sizeof(limb); i++) {
      if(!body) continue;
      if(!body[limb[i]]) continue;
      if(member_array(type, body[limb[i]]["armour"]) != -1) {
        if(member_array(type, body[limb[i]]["armour"]) == 0)
          body[limb[i]]["armour"] = body[limb[i]]["armour"][1..sizeof(body[limb[i]]["armour"])-1];
        else if(member_array(type, body[limb[i]]["armour"]) == sizeof(body[limb[i]]["armour"])-1)
          body[limb[i]]["armour"] = body[limb[i]]["armour"][0..sizeof(body[limb[i]]["armour"])-2];
        else
          body[limb[i]]["armour"] = body[limb[i]]["armour"][0..member_array(type, body[limb[i]]["armour"])-1] + body[limb[i]]["armour"][member_array(type, body[limb[i]]["armour"])+1..sizeof(body[limb[i]]["armour"])-1];
      }
        body[limb[i]]["ac"] -= arm_class;
        body[limb[i]]["armour_ob"] -= ({ arm });
    }
    return 1;
}

void set_fingers(int x) {
    all_my_fingers = x;
}

int query_fingers() { return all_my_fingers; }

void set_wielding_limbs( string *str) {
    int i;

    for(i=0; i<sizeof(str); i++) {
        if(member_array(str[i], limbs) == -1) continue;
        body[str[i]]["wieldable"] = 1;
    }
}

void add_wielding_limb(string str) {
    if(member_array(str, limbs) == -1) return;
    body[str]["wieldable"] = 1;
}

string *query_wielding_limbs() {
    string *tmp;
    int i;
    tmp = ({});

    for(i=0; i<sizeof(limbs); i++) {
        if(body[limbs[i]]["wieldable"]) 
            tmp += ({ limbs[i] });
    }
    return tmp;
}

void fix_limbs() {
    int i;

    for(i=0; i<sizeof(limbs); i++) {
        body[limbs[i]]["armour"] = ({});
        body[limbs[i]]["armour_ob"] = ({});
        body[limbs[i]]["ac"] = 0;
        body[limbs[i]]["weapon"] = 0;
    }
    wielded = ([]);
}

string *query_severed_limbs() {
    if(!severed) return ({});
    else return keys(severed);
}
string *query_limbs_wielded() { return (wielded ? keys(wielded) : ({})); }
object *query_wielded() { return (wielded ? values(wielded) : ({})); }

object query_weapon(string limb) {
    if(!wielded) return 0;
    if(!wielded[limb]) return 0;
    return wielded[limb];
}

//  initialize the variables

void init_complex_body() {
    target_limb = "";
}

void heal_limb(string str, int x) {
    if(member_array(str, limbs) == -1) return;
    if(!body[str]) return;
    body[str]["damage"] -= x;
    if(body[str]["damage"] < 0) body[str]["damage"] = 0;
}

int severed_limb(string limb) {
//  int temp;
    string childlimb;

    if(!body[limb]) return 0;
    childlimb = body[limb]["limb_ref"];
    if(childlimb == "FATAL") {
        this_object()->set_hp(-100);
        return 2;
    }
    if(childlimb == "") {
        remove_limb(limb);
        return 1;
    }
    if(!body[childlimb]) {
        remove_limb(limb);
        return 1;
    }
/*  why the hell was this here? -wiz Sun Feb 24 23:58:44 HST 2002
    temp = body[childlimb]["damage"];
    if(temp < body[childlimb]["max_dam"]) {
        do_damage(childlimb, 100);
        check_on_limb(childlimb);
    }
    just remove it.
*/
    remove_limb(childlimb);
    remove_limb(limb);
    return 1;
}

int check_on_limb(string limb) {
    object weap;
    object *arm;
//    string *locations;
    int i;

    object old_limb;

    if(!body[limb]) return 0;
    if(body[limb]["damage"] > body[limb]["max_dam"]) {
        if(wizardp(this_object()) && !this_object()->query_killable()) {
            message("my_combat", sprintf("If you were not immortal, you would "
              "lose your %s right now!", limb), this_object());
            body[limb]["damage"] = 0;
            return 1;
        }
    if((limb == "torso") || (limb == "head"))
      message("my_combat", "A mortal blow is dealt to your body!", this_object());
      else message("my_combat", sprintf("Your %s is severed!",limb),
        this_object());
        if(limb == "torso") tell_object(environment(this_object()),this_object()->query_cap_name()+" is dealt a mortal blow to the "+limb+"!", this_object());
        else tell_room(environment(this_object()),this_object()->query_cap_name()+" has "+this_object()->query_possessive()+" "+limb+" severed!", this_object());
        weap = wielded[limb];
        if (!weap) weap=wielded[body[limb]["limb_ref"]];
        if(weap) {
            remove_weapon_from_limb(weap);
            weap->set_not_equipped();
        }
        arm = body[limb]["armour_ob"];
        if(sizeof(arm)) {
            for(i = 0; i<sizeof(arm); i++) {
              if (arm[i]) {
                remove_armour_from_limb(arm[i], (string *)arm[i]->query_actual_limbs());
                arm[i]->set_not_equipped();
              }
            }
        }
        old_limb = new(OB_BODY_PART);
        old_limb->set_limb(query_cap_name(), limb);
        old_limb->move(environment(this_object()));
        if(weap) weap->move(old_limb);
        if(arm) {
            for(i=0; i<sizeof(arm); i++) {
                arm[i]->move(old_limb);
            }
        }
        this_object()->add_hp(-70);
        this_object()->add_heal_rate_bonus("hp", -5);
        return severed_limb(limb);
    }
    return 1;
}


void add_death(string str) {
    if(!str) return;
    if(!deaths) deaths = ({ ({str, time()}) });
    else deaths += ({ ({ str, time() }) });
}
mixed *query_deaths() { return deaths; }



void set_target_limb(string str) {
    if(!stringp(str)) return;
    if(member_array(str, limbs) == -1) return;
    target_limb = str;
}
