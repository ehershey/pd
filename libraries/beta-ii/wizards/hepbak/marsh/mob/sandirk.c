#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("sandirk");
   set_id( ({ "sandirk"}) );
   set_short("sandirk");
   set_long("A sandirk. Long and spiney, the sandirk looks like a snake with armour.");
   set_level(53);
   set_body_type("snake");
   set_alignment(0);
   set_race("sandirk");
   set_class("fighter");

      }
