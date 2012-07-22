#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside Burham Woods");
set_day_long("The trees here are protect you from exposure to the battlefield. The ground is soft and comfortable padded by the many leaves that fall at this time. Northwards you see tents.");
set_night_long("You can barely spot the moon from the base of the forest. It is
quite cold because of the mist from the sea. You wish there was a fire that
warm yourself up at. You spot a campfire north.");
set_items(([
"sunlight" : "Just barely any.",
"canopy" : "The trees grow quite tall.",
"ground" : "Soft and sticky.",
"moon": "A full moon.",
"trees": "Don't kid yourself.. trees? in a forest?"
]));

set_smell("default","The ocean and nature mix into a sweet scent.");
set_listen("default","The sounds of swords clashing echoes throughout.");
set_exits( ([ "west": "/wizards/powerman/room/forestwesta7.c",
              "north": "/wizards/powerman/room/forestwestb6.c",
              "east" : "/wizards/powerman/room/fielda5.c", ]));
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
