#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Inside Burham Woods");
set_day_long("A neatly kept tent. A few lanterns are left behind here. The bed of leaves is very well made. A plank of wood rests under 4 rocks to form a primitive table, there are stones and sticks arranged a weird pattern on it.");
set_night_long("The few lanterns here keep the tent well lit. The neatly kept tent allows for many people to enter. You stare at the pattern the rocks and sticks that are formed on the plank of wood not knowing what it is.");
set_items(([
"pattern" : "Oh! It is a map of the battlefield!",
"map"     : "The map is of the woods surrounding the battlefields by three sides, the castle being at the far south.",
"leaves" : "Quite soft for a bed.",
"pile" : "The pile of leaves form a bed.",
"lanterns": "To keep the tent lit at night",
]));
set_smell("default","The stale air is starting to make you dizzy.");
set_listen("default","The muffled sounds of battle is heard.");
set_exits( ([ "out": "/wizards/powerman/room/foresteasta2.c"]));
}

void reset()
{
 ::reset();
if(query_night() && !present("captain"))
{
new("/wizards/powerman/arm/malplotcapt")->move(this_object());
}
else
if(!present("captain")) {
}
}
