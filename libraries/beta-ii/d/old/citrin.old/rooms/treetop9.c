// Coded by Whit

#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
::create();
set_name("Amoung the treetops");
set_day_long("The light from the sun filters in this area "
"making this a bright area.  Leaves ruffle in the trees "
"from the wind.  The walkway creaks and sways in the wind.");
set_night_long("The light from the moon filters in this area "
"making this a bright area.  Leaves ruffle in the trees "
"from the wind.  The walkway creaks and sways in the wind.");

set_listen("default", "The leaves rustle in the wind.");
set_properties(([ "light" : 1, "night light" : 1, "forest" : 1, ]));
set_exits(([
"south" : ROOMS"treetop7.c",
"northwest" : ROOMS"treetop10.c",
]));

}
