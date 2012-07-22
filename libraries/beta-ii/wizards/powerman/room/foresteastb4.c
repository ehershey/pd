#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside Burham Woods");
set_day_long("You reach the edge of the woods. You can see the shoreline from
where you are.  The ground is soft and comfortable padded by the many leaves
that fall at this time. It is such a shame that this area has been turned into
a battlefield.");
set_night_long("You can barely spot the moon from the base of the forest. It is
quite cold because of the mist from the sea. You wish there was a fire that
warm yourself up at.");
set_items(([
"sunlight" : "Just barely any.",
"canopy" : "The trees grow quite tall.",
"ground" : "Soft and sticky.",
"moon": "A full moon.",
"trees": "Don't kid yourself.. trees? in a forest?"
]));

set_smell("default","The ocean and nature mix into a sweet scent.");
set_listen("default","The sounds of swords clashing echoes throughout.");
set_exits( ([ "south": "/wizards/powerman/room/foresteastb5.c",
              "north": "/wizards/powerman/room/foresteastb3.c",
              "west" : "/wizards/powerman/room/foresteasta4.c", ]));
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
