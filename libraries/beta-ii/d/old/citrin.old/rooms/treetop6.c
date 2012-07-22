// Coded by Whit

#include <citrin.h>
#include <std.h>
inherit ROOM;

int leap(string str);
int southwest(string str);

void init() {
::init();
add_action("southwest", "southwest");
add_action("leap", "leap");
}

void create() {
::create();
set_name("Amound the Treetops");
set_long("The winds that blow here make the walkway rock back "
              "and fourth.  The sun shines through here making this "
            "a very bright area.");
set_properties(([
           "light" : 1,
           "night light" : 1,
           "forest" : 1,
]));
set_exits(([
"northeast" : ROOMS+"treetop7",
"southwest" : "/std/void",
]));
}

int southwest(string str) {

if ("/d/citrin/rooms/treetop5"->query_exit("northeast") != "/d/standard/void")  {
this_player()->move_player(ROOMS"treetop5.c");
return 1;
}

write("The walkway has collapsed.  You may have to leap over it to get to the other side.");
return 1;
}

int leap(string str) {
if (str != "walkway") {
notify_fail("Leap over what?");
return 1;
}
write("You leap across the weak part of the walkway.");
say(this_player()->query_cap_name()+" leaps across to the other side.");
this_player()->move_player(ROOMS"treetop5.c");
return 1;
}
