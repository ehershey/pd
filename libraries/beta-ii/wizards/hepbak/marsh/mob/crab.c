#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("male");
   set_name("crab");
   set_id( ({ "crab"}) );
   set_short("blue crab");
   set_long("A short body, with two pincers.");
   set_level(40);
   set_body_type("crab");
   set_alignment(10);
   set_race("blue");
      }
