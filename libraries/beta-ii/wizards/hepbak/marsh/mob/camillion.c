#include <std.h>
#include <marsh.h>
inherit MONSTER;
void create() {
   ::create();
   set_name("chameleon");
   set_id( ({ "chameleon"}) );
   set_short("chameleon");
   set_long("It's sandy in color, but it doesn't quite blend in with the desert.");
   set_level(57);
   set_body_type("lizard");
   set_alignment(30);
   set_race("lizard");
      }
