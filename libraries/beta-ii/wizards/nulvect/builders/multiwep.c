#include <std.h>

inherit WEAPON;

void create() {
  ::create();
  set_name("multipurpose weapon");
  set_id(({"weapon","testwep","wep","knife","proj",
           "spear","blade","sword","axe","flail", "whip",
           "blunt", "bow", "ranged", "staff", "club"}));
  set_short("a multipurpose weapon");
  set_long("It does everything.");
  set_weight(10);
  set_wc(8);
  set_type("blade");
}

int query_auto_load() {
  object env;
  if ((env=environment()) &&
      env->query_name() == "rull")
        return 1;
}

string query_long() {
  return "Type: "+query_type()+"  WC: "+query_wc();
}

void init() {
  ::init();
  add_action("change_type","type");
  add_action("change_wc","WC");
  add_action("max","max");
  add_action("mob","mob");
  add_action("sub","sub");
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
  this_player()->force_me("clone /wizards/rull/testmon.c");
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
    "black":"dragon"
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
    else if (tp->query_race() == "dragon") {
      tp->set_race("imp");
      tp->new_body();
    }
    tp->fix_vital_bonus();
    tp->force_me("wizheal");
    max("");
    return 1;
  }
}

