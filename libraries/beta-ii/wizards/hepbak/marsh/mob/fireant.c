#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_name("fireant");
   set_id( ({ "fireant","ant"}) );
   set_short("fireant");
   set_long("The body is totally engulfed with flames.");
   set_level(50);
   set_body_type("insectoi");
   set_alignment(30);
   set_race("insect");
   set_class("mage");
   set_subclass("pyromancer");
   set_spells( ({"sear"}) );
   set_spell_chance(30);

      }
