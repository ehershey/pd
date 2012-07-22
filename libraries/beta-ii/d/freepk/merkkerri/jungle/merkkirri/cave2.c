#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Within the Blacktooth hideout");
set_long("This room was once used for supplies but now looks quite bare.  Evidently the Blacktooth Renegades have fallen upon hard times.");
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"south" : MJUNGLE "cave1.c",
]));
set_items(([
]));
}

void reset() {
::reset();
}
