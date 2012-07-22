#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("child");
   set_id( ({ "little boy" }) );
   set_short("a little boy");
   set("aggressive", 20);
   set_level(50);
   set_long("The little boy crawls around on the floor.  How could such an ancient fiend be so innocent?.");    
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
