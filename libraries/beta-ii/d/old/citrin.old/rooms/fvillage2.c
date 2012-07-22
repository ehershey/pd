// Coded by Whit

#include <std.h>
#include <citrin.h>

inherit ROOM;

void create() {
::create();
set_name("Faerie Village");
set_long("The small faerie village comes to an end.  The "
"end of the forest is to the north.  The walkway continues "
"no further.  To the north can be seen the city of <insert "
"name here>.");

set_properties(([ "light" : 1, "night light" : 1, "village" : 1 ]));
set_exits(([
"south" : ROOMS"fvillage1.c",
]));
}

void reset() {
::reset();
if(!present("faerie"))
new(MON"faerie1.c")->move(this_object());
}
