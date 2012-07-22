#include <std.h>
#include <lodos.h>
inherit MONSTER;
static int oi;

void create() {
 ::create();
   set_short("a holy paladin");
   set_id( ({ "paladin", "holy paladin" }) );
   set_name("paladin");
   set_level(26);
   set_long("The protector of good, slayer of evil, the paladin guards "
      "the moral stature of the Lodian towers.");
   set_body_type("human");
   set_race("elf");
   set_class("fighter");
   set_subclass("paladin");
   set_skill("blade", 130);
   set_gender("male");
   set_heart_beat(1);
   set_alignment(450);
   make(WEA"longswr");
}

void heart_beat() {
 ::heart_beat();
   if (!oi) { force_me("wield sword"); oi = 1;}
}
