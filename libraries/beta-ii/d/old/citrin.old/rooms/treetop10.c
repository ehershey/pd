// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
set_name("Amoung the treetops");
set_long("The forest suddenly seems to end.  The pathway "
"to the north and will go no farther.  Looking out beyond "
"the horizon is the sight of the city <insert here>.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1, ]));
set_exits(([
"southeast" : ROOMS"treetop9.c",
]));

}
