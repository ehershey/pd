#include <std.h>
#include <marsh.h>
inherit MOUNT;
void create() {
   ::create();
   set_gender("male");
   set_name("camel");
   set_id( ({ "camel"}) );
   set_short("camel");
   set_long("This creature is known to travel long distances without water.");
   set_level(55);
   set_body_type("horse");
   set_alignment(30);
   set_race("camel");
      }
