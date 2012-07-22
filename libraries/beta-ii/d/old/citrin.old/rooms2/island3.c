// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("a small deserted island");
set_day_long("The path is made from a white sand.  Its weight keeps the "
"foilage from overgrowing the path.  Trees line the path.  The sand "
"glistens in the sun.");
set_night_long("The path is made from a white sand.  Its weight keeps the "
"foyage from overgrowing the path.  Trees line the path.  The sand "
"glistens in the sun.");
set_properties(([ "light" : 0, "night light" : 0, "island" : 1 ]));

set_items(([

"path" : "It is made from a white glistening sand.",
]));

set_exits(([

"northwest" : ROOM2"island4.c",
"east" : ROOM2"island2.c",
]));
}
