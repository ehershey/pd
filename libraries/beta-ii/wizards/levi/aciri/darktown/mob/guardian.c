include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("guard");
   set_id( ({ "guardian of the ball" }) );
   set_short("Guardian of the Ball");
   set("aggressive", 20);
   set_level(500);
   set_long("The guardian of the ball stands before the tiny door with a grin on his face.  He has recently fed, it would seem, possibly on the fountain just south of here.  He will not admit you without an invitation...  or a fight!.");    
   set_body_type("human");
   set_class("monk");
   set_subclass("dark");
   set_spell_chance(70);
   set_spells( ({ "armageddon", "snapkick" }) );
   set_skill("melee", 10000);
   set_skill("attack", 2000);
   set("race", "vampire");
   set_gender("male");
}


