#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
::create();
set_name("raknid cleric");
set_id( ({ "cleric","raknid","rcleric" }) );
set_short("A raknid cleric");
set_long("This is a fairly small raknid. He has no rippling muscles or any"
        " type of facial features. You feel this is an easy prey.");
set_subclass("cleric");
set_level(70);
set_race("raknid");
set_body_type("raknid");
set_gender("male");
set_alignment(1500);
set_skill("magic attack",200);
set_skill("belief",400);
set_skill("healing",400);
set_skill("faith",400);
set_spells( ({"lifewarp"}) );
set_spell_chance(30);
      }
