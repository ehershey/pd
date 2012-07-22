#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("hyena");
   set_id( ({ "hyena","cub"}) );
   set_short("A hyena cub");
   set_long("This playful dog, has hopes of being a leader someday.");
   set_level(20);
   set_body_type("canine");
   set_alignment(10);
   set_race("canine");
   set_class("fighter");
   set_skill("attack",110);

      }
