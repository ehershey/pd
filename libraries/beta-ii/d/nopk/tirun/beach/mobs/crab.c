#include <std.h>
inherit MONSTER;

void create() {
    ::create();
   set_name("crab");
   set_id( ({ "crab" }) );
   set_short("an angry crab");
   set("aggressive", 10);
   set_level(random(5)+8);
   set_long("The crab crawls in your direction, it seems upset "
           "at your presence here.");
    set_body_type("merperson");
   set("race", "crab");
   set_gender("male");
}
