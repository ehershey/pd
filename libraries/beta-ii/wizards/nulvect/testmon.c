
#include <std.h>

//inherit MONSTER;
inherit PET;
//inherit "/wizards/nulvect/std/monster";
//inherit "/wizards/nulvect/monster";

int hp;

int change_level(string str);
int check_spit(string cmd, string arg);
int do_explode(string str);
int do_claim(string str);

void create() {
  ::create();
  set_name("oozy");
  set_race("human");
  set_body_type("human");
  set_gender("neuter");
  set_id(({"ooze","testmon"}));
  set_short("A gelatinous ooze");
  set_long("A big blob of ooze that looks like a booger.");
  set_level(25);
  set_class("rogue");
  set_subclass("thief");
  hp=query_hp();
  set_command_check( (: check_spit :) );
  add_action("do_explode", "explode");
//  if (find_player("nulvect")) set_owner(find_player("nulvect"));
  set_spell_chance(1);
//  set_spells( ({ "pain", "dispell" }) );
  /*
  set_inventory( ([
    "/wizards/nulvect/multiwep" : ({ 3, "wield wep", "wield wep" }),
    "/d/nopk/tirun/obj/misc/backpack" : "wear pack",
  ]) );
  */
}

int do_explode(string str) {
  message("emote", "Testmon EXPLODES!", environment(this_object()));
  return 1;
}

int check_spit(string cmd, string arg) {
  if (cmd == "spit") return 0;
  return 1;
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
  add_action("do_claim", "claim");
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

int do_claim(string str) {
  set_owner(this_player());
  message("info", "Claimed Testmon.", this_player() );
  return 1;
}
