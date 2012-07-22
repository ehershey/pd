#include <std.h>

inherit MONSTER;

void create() {
 ::create();
   set_name("deer");
   set_id(({"deer"}));
   set_short("a young deer");
   set_long("The deer runs across the trail, hoping it hasn't been "
          "seen.");
    set_gender("female");
   set_race("deer");
   set_body_type("equine");
   set_level(5);
   set_patrol(4, ({ "west", "east" }) );
   "/daemon/chat"->do_raw_chat("cre", "Deer <cre> woo yeah im a deer");  
}
