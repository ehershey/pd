#include <dquest.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void init() {
    ::init();
add_action("enter_portal" , "enter");
}

void create() {
::create();
set_short("A dead end");
set_long("%^BOLD%^BLACK%^After what feels like an eternity you come across a portal at the end of the passageway.%^RESET%^");
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"north": DQUEST "dquest102.c",
]));
set_items(([
]));
new(MJUNGLE "portal")->move(this_object());
}

int enter_portal(string what) {
  if (what != "portal") return 0;
this_player()->move_player(DQUEST "dquest1.c", "into the glowing portal
and vanishes without a trace..");
    return 1;
}
