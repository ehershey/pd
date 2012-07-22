#include <mjungle.h>
#include <locations.h>
#include <std.h>
inherit ROOM;

void init() {
    ::init();
add_action("enter_portal" , "enter");
}

void create() {
::create();
set_short("A hidden chamber within the tree");
set_long("You have discovered a secret room containing a portal.  Where that portal leads is another mystery...");
set_properties((["light" : 3, "indoors" : 3,]));
set_exits(([
"out" : MJUNGLE "treeroom.c",

]));
set_items(([
]));
new(MJUNGLE "portal")->move(this_object());
}

int enter_portal(string what) {
  if (what != "portal") return 0;
this_player()->move_player(SQUARE_LOC, "into the glowing portal
and vanishes without a trace.");
    return 1;
}
