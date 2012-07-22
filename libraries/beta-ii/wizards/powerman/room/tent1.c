#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside Burham Woods");
set_day_long("You're inside an empty tent, there are piles of leaves made for beds, a lantern remains on the ground. There is some gauze and bandages lying around. This room looks like resting tent of injured and resting soldiers.");
set_night_long("This tent is being used to rest soldiers that are injured in anyway. The lantern glows dimly, not allowing you to see very well.");
set_items(([
"gauze" : "Lying around on the floor.",
"leaves" : "Quite soft for a bed.",
"pile" : "The pile of leaves form a bed.",
"lantern": "To keep the tent lit at night",
]));
set_smell("default","The stale air is starting to make you dizzy.");
set_listen("default","The muffled sounds of battle is heard.");
set_exits( ([ "out": "/wizards/powerman/room/forestwestb2.c"]));
}

void reset()
{
 ::reset();
if(query_night() && !present("soldier"))
{
new("/wizards/powerman/arm/injsold")->move(this_object());
new("/wizards/powerman/arm/injsold")->move(this_object());
new("/wizards/powerman/arm/injsold")->move(this_object());
new("/wizards/powerman/arm/injsold")->move(this_object());
}
else
if(!present("soldier")) {
}
}
