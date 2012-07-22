// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
set_name("Amoung the treetops");
set_long("The path suddenly turns old and rotten.  Vegetation "
"has overgrown the walkway.  Trees surround all sides of the "
"walkway.");
set_listen("default", "The sound of fluttering fill the air.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1, ]));
set_exits(([
"southwest" : ROOMS"treetop7.c",
"northeast" : ROOMS"fvillagee.c",
]));

}
