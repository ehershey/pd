#include <std.h>
inherit MONSTER;
void create() {
::create();
set_name("black widow");
set_id( ({ "black","raknid","widow" }) );
set_short("A black widow");
set_long("She looks to be the most powerful leader.  She looks very frightening.");
set_subclass("monk");
set_level(75);
set_race("raknid");
set_body_type("raknid");
set_gender("female");
}
#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("male");
   set_name("wasp");
   set_id( ({ "wasp"}) );
   set_short("wasp");
   set_long("A small little pesky bug with a stinger.");
   set_level(45);
   set_body_type("insctwgd");
   set_alignment(15);
   set_race("insect");
      }
