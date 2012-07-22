#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("female");
   set_name("magic hyena");
   set_id( ({ "hyena","magic hyena"}) );
   set_short("A magic hyena");
   set_long("Seems to be very powerful.");
   set_level(30);
   set_body_type("canine");
   set_alignment(10);
   set_race("canine");
   set_subclass("druid");
set_skill("magic attack",200);
set_skill("nature",400);
set_spells( ({"icestorm"}) );
set_spell_chance(30);
      }
