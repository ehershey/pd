
#include <std.h>

//inherit UNDEAD;
inherit MONSTER;
//inherit "/wizards/nulvect/std/monster";
//inherit "/wizards/nulvect/monster";

int hp;

int change_level(string str);

void create() {
  monster::create();
  set_name("testmon");
  set_race("ooze");
  set_body_type("elf");
  set_gender("neuter");
  set_id(({"ooze","testmon"}));
  set_short("A gelatinous ooze");
  set_long("A big blob of ooze that looks like a booger.");
  set_level(25);
  set_class("rogue");
  set_subclass("thief");
  set_listen("stones", query_cap_name()+" says: I like to eat stones.");
  hp=query_hp();
  set_says(80, ({ "Hi there.", "Give me something to eat." }), 0);
  set_emotes(70, ({ query_cap_name()+" munches on something.", query_cap_name()+"'s stomach gurgles." }), 0);
}

void heart_beat() {
  int x;
  ::heart_beat();

  if (!this_object() || !environment()) return;

  if (hp > query_hp()) {
    x=hp-query_hp();
    message("test","%^YELLOW%^*** "+x+" damage ***%^RESET%^",environment());
  }
  
  else
  if (hp < query_hp()) {
    x=query_hp()-hp;
    message("test","%^BOLD%^%^CYAN%^*** "+x+" healed ***%^RESET%^",environment());
  }
  hp=query_hp();
}

void init() {
  ::init();
  add_action("change_level", "level");
}

int change_level(string str) {
  this_object()->set_level(to_int(str));
  this_object()->set_bleeding(0);
  if (present("testmon 2",environment()))
    return notify_fail("Setting multiple mobs to level "+str+".\n");
  else {
    message("info","Setting mob to level "+str+".",this_player());
    return 1;
  }
}

