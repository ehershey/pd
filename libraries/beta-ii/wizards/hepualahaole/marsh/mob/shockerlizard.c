#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("male");
   set_name("lizard");
   set_id( ({ "lizard","shockerlizard","shocker lizard",}) );
   set_short("shocker lizard ");
   set_long("Electrical energy sparks all over this lizard.");
   set_level(60);
   set_body_type("lizard");
   set_alignment(-200);
   set_race("lizard");
   set_subclass("wizard");
   set_class("mage");
   set_skill("attack",200);
   set_skill("magic attack",200);
   set_spells( ({"shock"}) );
   set_spell_chance(30);
      }
