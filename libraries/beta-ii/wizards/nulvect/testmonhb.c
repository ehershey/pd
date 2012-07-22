
#include <std.h>

inherit MONSTER;
//inherit "/wizards/nulvect/std/monster";

int hp;

int change_level(string str);

void create() {
  ::create();
  set_name("ooze");
  set_race("ooze");
  set_body_type("human");
  set_gender("neuter");
  set_id(({"ooze","testmon"}));
  set_short("A gelatinous ooze");
  set_long("A big blob of ooze that looks like a booger.");
  set_class("rogue");
  set_subclass("thug");
  set_level(25);
  hp=query_hp();
  set_spell_chance(80);
  set_spells( ({"headbutt"}) );
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
  if (present("testmon 2",environment()))
    return notify_fail("Setting multiple mobs to level "+str+".\n");
  else {
    message("info","Setting mob to level "+str+".",this_player());
    return 1;
  }
}

