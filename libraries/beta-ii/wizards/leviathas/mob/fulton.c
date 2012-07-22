#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("fulton");
   set_id( ({ "fulton" }) );
   set_short("%^MAGENTA%^FULTON!!!");
   set("aggressive", 1);
   set_level(2);
   set_long("Fulton is going to ruin your life, child.");    
   set_body_type("human");
   set_class("monk");
   set_subclass("dark");
   set_spell_chance(50);
   set_spells( ({ "denmak", "snapkick" }) );
   set_skill("melee", 200);
   set_skill("attack", 200);
   set("race", "devil");
   set_gender("female");
}
