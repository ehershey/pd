#include <std.h>
#include <tepes.h>
inherit ROOM;
void init() {
    ::init();
    add_action("dive_check", "look");
}

void create() {
::create();
  set_short("A rock reef");
  set_long("A shelf top plateau with sheer drop offs on either side of the
reef. Minature rainbows are formed in the mist from the bright sun. The smooth
shelf provides a nice place to rest. Swells and strong currents seperate you
from the mainland.");
  set_night_long("A shelf top plateau with sheer drop offs on either side of
the reef. The dark coral is slippery and jagged in places but the shelf is flat
and provides a nice place to rest. Waves break upon the reef crashing into the
darkness below.");
  set_items(([
    "reef" : "A submerged ridge of rock.",
    "bay" : "A body of water partially enclosed.",
    "waves" : "Waves crash into the reef.",
    "beach" : "A sandy beach.",
    "peninsula" : "A stretch of land almost completely surrounded by
water."]));
   set_smell("default", "The odors of the bay fill the air.");
   set_listen("default", "The sea roars around you.");
   set_properties(([
    "light" : 2,
    "night light" : 1,
]));




}
int dive_check(string str) {
 if(this_player()->query_level() < 20)
   message("info", "The water looks too harsh to swim in");
  return 0;
    if(!str) {
        notify_fail("You cannot look in that direction.\n");
        return 0;

    }
    if(str != "water") {
        notify_fail("You cannot look in that direction.\n");
        return 0;
    }
    
    message("info", (string)this_player()->query_cap_name()+" peers into the rapid waters.", this_object(), ({ this_player() }));
    add_exit(ROOMS"guest37", "swim");
    add_invis_exit(ROOMS"b_room5.c", "swim");
    call_out("go_hole", 60);
    return 1;
}

void go_hole() {
all_inventory(this_object()));
    remove_exit("swim");
}


