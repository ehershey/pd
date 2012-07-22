#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("father");
   set_id( ({ "father" }) );
   set_short("a father");
   set("aggressive", 20);
  set_level(50);
   set_long("The father leans against the wall and watches quietly.");
    set_body_type("human");
   set_class("monk");
   set_subclass("dark");
   set_spell_chance(50);
   set_spells( ({ "denmak", "snapkick" }) );
   set_skill("melee", 200);
   set_skill("attack", 200);
   set("race", "vampire");
   set_gender("male");
}


