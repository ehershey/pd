#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("male");
   set_name("bird");
   set_id( ({ "bird"}) );
   set_short("bird");
   set_long("A scavenger, looking for food.");
   set_level(45);
   set_body_type("fowl");
   set_alignment(15);
   set_race("fowl");
      }
