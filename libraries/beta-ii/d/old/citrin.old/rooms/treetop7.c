// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
set_name("Amoung the tree tops");
set_day_long("The sun shines through the treetops warming "
"this area with its strong rays.  The walkway sways in the "
"wind making this a very dangerous place.  Some vines have "
"wraped themselves around the hand grip.");
set_night_long("The sky can clearly be seen through the "
"treetops.  The walkay sways in the wind making it a very "
"dangerous place.  Some vines have wraped themselves around "
"the hand grip.");

set_items(([
("grip", "hand grip") : "The hand grip is covered with vines.",
]));
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1, ]));
set_exits(([
"southwest" : ROOMS"treetop6.c",
"north" : ROOMS"treetop9.c",
"northeast" : ROOMS"treetop8.c",
]));
}
