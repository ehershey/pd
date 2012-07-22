#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 4, "night light" : 4, "indoors" : 1]) );
set_smell("default", "A strong, earthy smell fills the air.");
set_listen("default", "Small rocks can be heard falling toward the ground.");
set_short("climbing up the rocky slope");
set_long("The climb up the slope is very difficult, especially in comparison to jumping down.  There seems to be no stopping places or ledges the entire way up, although some footing allows for short resting.  Thankfully, the climbable path leads straight to the hole atop the cavern.");
set_items(([
({"rock", "rocks"}) : "Although many rocks are sharp and jagged, there are plenty of flat ones to aide climbing down..",
({"hole", "light"}) : "There is a hole where light comes through, seen straight above..",
]));
set_exits(([ "hole" : ROOMS "x.c"]));
}
