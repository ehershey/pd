// Coding by Whit
// Coded for Primal Darkness
// openpath_3.c

#include <std.h>
#include <citrin.h>
inherit ROOM;
int climb(string str);

void init() {
::init();
add_action("climb","climb");
}

void create() {
::create();
    set_short("Citrin Forest");
    set_day_long("This section of the forest is unusually light.  The "
                 "trees have spread enough to let the sun shine through "
                 "There are many small foot prints here that looks to "
                 "to a small animal.  There are vines hanging down "
                 "from one of the oak trees");
    set_night_long("This section of the forest is unusually light.  The "
                 "trees have spread enough to let the sun shine through "
                 "There are many small foot prints here that looks to "
                 "to a small animal.  There are vines hanging down "
                 "from one of the oak trees");
    set_smell("default", "The smell of animals is here.");
    set_items(([
        "vine" : "It looks like this vine may be climable",
        ("tree", "trees") : "The trees move in the slight wind that blows through here.",
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 0,
        "forest" : 1,
    ]));
    set_exits(([
        "west" : ROOMS+"openpath_2.c",
        "southeast" : ROOMS+"openpath_4.c",
    ]));
}
int climb(string str) {
if(str != "vine") {
notify_fail("Climb what?");
return 0;
}
if(this_player()->query_stats("dexterity") < random(30)) {
write("You slip and fall.");
say(this_player()->query_cap_name()+" falls on his butt.");
return 2;
 }
write("You climb the vine.");
say(this_player()->query_cap_name()+" climbs a vine.");
this_player()->move_player(ROOMS"treetop1.c");
return 1;
}
