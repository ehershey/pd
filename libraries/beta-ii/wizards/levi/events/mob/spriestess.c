#include <std.h>
#include <sp.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("priestess");
   set_id( ({ "priestess" }) );
   set_short("a young priestess");
   set("aggressive", 1);
  set_level(20);
   set_long("The young priestess is very weak looking and pale.  She must have fasted for a long time.");
    set_body_type("human");
   set_class("clergy");
   set_subclass("monk");
   set("race", "human");
   set_gender("female");

}

