#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The face of a cliff");
set_day_long("You are now standing at the base of a large cliff.  You notice a cave that has been partially obscured by a boulder and some plantlife.");
set_night_long("You are now standing at the base of a large cliff.  You notice a cave that has been partially obscured by a boulder and some plantlife.");

set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"cliff" : "The cliff is quite steep but offers many footholds that would making climbing it possible.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"cave" : "The cave is very dark and looks as if an attempt was made to hide it.",
"boulder" : "The boulder appears to have been placed in a manner to disguise the cave's entrance.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"climb": MJUNGLE "mjungle41.c",
"southwest": MJUNGLE "mjungle34.c",
"enter": MJUNGLE "cave1.c",
]));
}

void reset() {
 ::reset();

}
