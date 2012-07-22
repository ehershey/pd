#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside a stone building");
set_long("This room is a small storage space used by the guards to keep belongings and supplies.  Several crates and barrels line the walls as well as heavy cloth bags.  The room otherwise is quite featureless.");
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"south" : MJUNGLE "outpost1.c",
]));
set_items(([
"bags" : "The bags contain clothing and various other supplies.  Nothing that really catches your attention.",
"crates" : "The crates are used to store rations and water for the guards.",
"barrels" : "Several barrels line the room.",
]));
}

void reset() {
::reset();
set_search("barrels", (: this_object(), "hidden_bracers" :));
set_smell("default", "The rooms smells moldy and stale.");
}
void hidden_bracers() {
message("my_action", "You discover a set of bracers inside one of the barrels.", this_player());
message("other_action", this_player()->query_cap_name()+" finds a set of bracers within one of the open crates.", this_object(), ({ this_player() }));
new(MOB "skull_bl")->move(this_object());
new(MOB "skull_br")->move(this_object());
remove_search("barrels");
}
