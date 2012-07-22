#include <std.h>
inherit ROOM;
void create () {
::create();
set_short("the base of the tower");
set_long("This is the bottom of the tower there is not much here except "
"a small window that shows a large tree outside.  the walls seem to "
"be made completely out of marble. as you look around"
"the circular room, you seem to get a little nervous about which way to "
"go.");
set_items(([
"window" : "it is an old victorian window about chest height.",
"tree" : "just an old oak tree.",
"floor" : "a smooth hard floor.",
"wall" : "the wall is very smooth, and cool to the touch."]));
set_properties(([
"light" : 3,
"night light" : 1]));
set_exits(([
"out" : "/wizards/manex/lobby.c",
"up" : "/wizards/manex/tower2.c",
]));
}
