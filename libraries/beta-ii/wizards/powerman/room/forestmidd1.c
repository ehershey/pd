#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside Burham Woods");
set_day_long("Not a lot of sunlight goes through the canopy and into the
forest. Burham Woods has much less corpses in it. The ground is soft and
comfortable padded by the many leaves that fall at this time. You cannot see
much but trees in here.");
set_night_long("You can barely spot the moon from the base of the forest. It is
quite cold because of the moisture in the area. You wish there was a fire that
warm yourself up at.");
set_items(([
"sunlight" : "Just barely any.",
"canopy" : "The trees grow quite tall.",
"ground" : "Soft and sticky.",
"moon": "A full moon.",
"trees": "Don't kid yourself.. trees? in a forest?"
]));

set_smell("default","Fresh blood and nature mix into a sweet scent.");
set_listen("default","The sounds of swords clashing echoes throughout.");
set_exits( ([ "west" : "/wizards/powerman/room/forestmidc1.c",
              "south"     : "/wizards/powerman/room/forestmidd2.c",
              "east" : "/wizards/powerman/room/forestmide1.c",
              "northwest": "/wizards/powerman/room/pathd.c" ]));
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
