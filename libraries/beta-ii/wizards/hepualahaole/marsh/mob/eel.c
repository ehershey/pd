#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("eel");
   set_id( ({ "eel"}) );
   set_short("eel");
   set_long("A snake-like creature that has an electrical aura around it.");
   set_level(45);
   set_body_type("snake");
   set_alignment(10);
   set_race("eel");
   set_class("mage");
   set_subclass("wizard");
   set_skill("attack",200);
   set_skill("magic attack",200);
   set_spells( ({"shock"}) );
   set_spell_chance(40);

      }

