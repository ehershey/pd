#include <std.h>
#include <daemons.h>

#define NAME_RULE_TIME 1137565000

inherit WEAPON;

void create() {
  weapon::create();
  set_name("multipurpose weapon");
  set_id(({"weapon", "multiwep", "testwep","wep","knife","proj",
           "spear","blade","sword","axe","flail", "whip",
           "blunt", "bow", "ranged", "staff", "club",
        "MUD_Master_Key"}));
  set_short("a multipurpose weapon");
  set_long("It does everything.");
  set_weight(10);
  set_wc(8);
  set_type("blade");
  set_item("info", (: ""+query_type()+": "+query_wc() :) );
  set_materials( ({ "unobtanium" }) );
}
int query_auto_load() {
  object env;
  if ((env=environment()) &&
      env->query_name() == "nulvect")
        return 1;
}

/*
string query_long() {
  return "Type: "+query_type()+"  WC: "+query_wc();
}
*/

int query_lit() { return 1; }
void init() {
  ::init();
  add_action("change_type","type");
  add_action("change_wc","WC");
  add_action("max","max");
  add_action("mob","mob");
  add_action("sub","sub");
  add_action("do_stats", "mystats");
  add_action("check_birthday", "namecheck");
}

int change_type(string str) {
  if (!wizardp(this_player())) return 0;
  set_type(str);
  if (present("testwep 2",environment()))
    return notify_fail("Changed types to "+str+".\n");
  message("info","Changed type to "+str+".",this_player());
  return 1;
}

int change_wc(string str) {
  if (!wizardp(this_player())) return 0;
  set_wc(to_int(str));
  if (present("testwep 2",environment()))
    return notify_fail("Changed WCs to "+str+".\n");
  message("info","Changed WC to "+str+".",this_player());
  return 1;
}

int max(string str) {

  int l=0, level;
  mapping s;
  string w;
  object who;

  if (!wizardp(this_player())) return 0;

  if (str && sscanf(str,"%d %s",l,w) == 2)
    who = find_player(w);
  else
    who = this_player();

  if (!who)
    return notify_fail("No one around by that name.\n");

  s = who->query_skills();
  level = who->query_level();

  foreach (string sk in keys(s)) {
    int max;
    if (l)
      max = l;
    else
      max = s[sk]["max"] * level / 2;
    who->set_skill(sk, max);
  }
  message("info","Skills maxed.",this_player());

  return 1;
}

int mob(string str) {
  if (!wizardp(this_player())) return 0;
  this_player()->force_me("clone /wizards/nulvect/testmon.c");
  return 1;
}

int sub(string str) {
  object tp=this_player();
  mapping subs = ([
    "warrior":"fighter",
    "berserker":"fighter",
    "ranger":"fighter",
    "paladin":"fighter",
    "antipaladin":"fighter",
    "wizard":"mage",
    "sorceror":"mage",
    "pyromancer":"mage",
    "necromancer":"mage",
    "druid":"clergy",
    "cleric":"clergy",
    "monk":"clergy",
    "kataan":"clergy",
    "thief":"rogue",
    "assassin":"rogue",
    "thug":"rogue",
    "scout":"rogue",
    "bard":"wanderer",
    "gypsy":"wanderer",
    "jester":"wanderer",
    "swashbuckler":"wanderer",
    "blue":"dragon",
    "red":"dragon",
    "white":"dragon",
    "black":"dragon",
    "vampire":"vampire",
  ]);
  
  if (!wizardp(tp)) return 0;

  if (!str || str == "" || member_array(str, keys(subs)) == -1)
    return notify_fail("Which sub?\n");

  else {
    tp->set_class(subs[str]);
    tp->set_subclass(str);
    message("info", "Sub changed to "+str+".", tp);
    if (subs[str] == "dragon") {
      tp->set_race("dragon");
      tp->new_body();
    }
  else if (subs[str] == "vampire") {
    tp->set_race("vampire");
    tp->new_body();
  }
    else if (tp->query_race() == "dragon" || tp->query_race() == "vampire") {
      tp->set_race("imp");
      tp->new_body();
    }
    tp->fix_vital_bonus();
    tp->force_me("wizheal");
    max("");
    return 1;
  }
}

int do_stats(string str) {
  object tp=this_player();
  string n;
  if (!wizardp(tp)) return 0;
  if (sscanf(str, "%d", n) != 1)
    return notify_fail("<mystats #>\n");
  foreach (string st in tp->query_all_stats())
    tp->set_stats(st, n);
  tp->fix_vital_bonus();
  message("info", "Stats set to "+(string)n+".", tp);
  return 1;
}
    
int is_quiver() { return 1; }
int use_arrow() { return 1; }
int query_arrows() { return 12; }

int check_birthday(string str) {
  object tp = this_player();
  object who;
  if (!wizardp(tp)) return 0;
  who = find_player(str);
  if (who->query_birthday() > NAME_RULE_TIME)
    message("info", "The name '"+str+"' was created AFTER the name rule.", tp);
  else
    message("info", "The name '"+str+"' was created BEFORE the name rule.", tp);
  return 1;
}
