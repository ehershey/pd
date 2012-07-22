#include <std.h>
#include <terra.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("guard");
   set_id( ({ "guard" }) );
   set_short("A Gigantic Guard");
   set("aggressive", 1);
   set_level(90);
   set_long("%^BOLD%^%^BLACK%^The huge guard blocks the stairs to the ball.");    
   set_body_type("human");
   set_class("fighter");
   set_subclass("");
   set_spell_chance(70);
   set_spells( ({ "stun", "warshout"}) );
   set_skill("melee", 300);
   set_skill("attack", 300);
   set("race", "titan");
   set_gender("male");
}


