#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("male");
   set_name("bee");
   set_id( ({ "bee"}) );
   set_short("bee");
   set_long("A small little pesky bug with a stinger.");
   set_level(35);
   set_body_type("insctwgd");
   set_alignment(15);
   set_race("insect");
      }
