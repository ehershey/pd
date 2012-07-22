#include <std.h>
#include <marsh.h>
inherit MONSTER;

void create() {
   ::create();
   set_gender("female");
   set_name("fish");
   set_id( ({ "rainbow","rainbow trout","fish"}) );
   set_short("A rainbow trout");
   set_long("The colors of the rainbow are brightly displayed on the side of this fish.");
   set_level(20);
   set_body_type("fish");
   set_alignment(10);
   set_race("fish");
   set_class("fighter");

      }
