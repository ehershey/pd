#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("female");
   set_name("crawfish");
   set_id( ({ "fish","crawfish"}) );
   set_short("crawfish");
   set_long("It slithers on the ground looking for water.");
   set_level(42);
   set_body_type("crab");
   set_alignment(15);
   set_race("crawfish");
      }
