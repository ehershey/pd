#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("female");
   set_name("water bug");
   set_id( ({ "bug","waterbug"}) );
   set_short("A waterbug");
   set_long("The waterbug looks almost like a spider but it spends it's time on the water.");
   set_level(25);
   set_body_type("insctwgd");
   set_alignment(20);
   set_race("insect");
   set_class("fighter");
   set_skill("attack",115);

      }
