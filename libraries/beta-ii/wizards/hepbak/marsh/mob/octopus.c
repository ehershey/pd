#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("male");
   set_name("octopus");
   set_id( ({ "octopus"}) );
   set_short("octopus");
   set_long("It's an underwater creature that has eight arms and one body.");
   set_level(40);
   set_body_type("octopus");
   set_alignment(0);
   set_race("octopus");
   set_class("fighter");

      }
