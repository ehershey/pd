#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside Burham Woods");
set_day_long("You reach the edge of the woods. You can see the shoreline from
where you are.  The ground is soft and comfortable padded by the many leaves
that fall at this time. You see tents set up south. ");
set_night_long("The moonlight reflects off the ocean to the north. You sight a
campfire to the south. You feel cold from the ocean breeze. You wish that there
was a fire to warm you up.");
set_items(([
"sunlight" : "Just barely any.",
"canopy" : "The trees grow quite tall.",
"tents" : "Set up by Soldiers.",
"ocean": "Beautiful.",
"trees": "Don't kid yourself.. trees? in a forest?"
]));

set_smell("default","The ocean and nature mix into a sweet scent.");
set_listen("default","The sounds of swords clashing echoes throughout.");
set_exits( ([ "south": "/wizards/powerman/room/forestwestb2.c",
              "west" : "/wizards/powerman/room/forestwesta1.c",
              "east" : "/wizards/powerman/room/forestmida1.c" ]));
}

void reset()
{
 ::reset();
if(query_night() && !present("soldier"))
{
new("/wizards/powerman/arm/forsold")->move(this_object());
new("/wizards/powerman/arm/forsold")->move(this_object());
}
else
if(!present("soldier")) {
new("/wizards/powerman/arm/forsold")->move(this_object());
new("/wizards/powerman/arm/forsold")->move(this_object());
new("/wizards/powerman/arm/forsold")->move(this_object());
}
}
