#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The heart of the jungle");
set_day_long("You are in the heart of the jungle.  Few if any outsiders ever reach these parts.  To the far southwest you see the glimmer of gold mixed in with the jungle surroundings.");
set_night_long("You are in the heart of the jungle.  Few if any outsiders ever reach these parts.  To the far southwest you hear chanting and voices similar to those heard at the Warlord's encampment.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"gold": "The glimmer of gold can be seen mixed within the jungle to the far southwest.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([
"northeast": MJUNGLE "mjungle32.c",
"south": MJUNGLE "mjungle45.c",
]));
}

void reset() {
 ::reset();
}
