#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_gender("male");
   set_name("fishskel");
   set_id( ({ "fish","fishskel","skel"}) );
   set_short("fish skel");
   set_long("All the meat fell of the bones, leaving you with a dead carcass.");
   set_level(39);
   set_body_type("crab");
   set_alignment(12);
   set_race("undead");
      }
