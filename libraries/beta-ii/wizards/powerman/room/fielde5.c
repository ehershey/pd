#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The battlefields");
set_day_long("Swords clashing, People screaming. The ground is trampled and
dirty. You are at the walls of Macbeth's castle. Corpses litter the ground. 
Within the thick smog of dust, you see reflections of sunlight off the weapons 
and armour of the soldiers in the battle.");
set_night_long("The battle rages on even deep into the night. There are fires
from destruction everywhere. Sword sparks make the battlefield seem like the
dark clear sky. You can't help but feel that you are stepping on corpses on the
ground. You are at the walls of Macbeth's castle. ");
set_items(([
"ground" : "Trampled and dirty.",
"sunlight"     : "Where else do you look for sunlight?",
"reflections" : "The sunlight bounces off of the armour and swords of the
soldiers.",
]));
set_smell("default","The Smell of blood and sweat is intense.");
set_listen("default","The battle roars on from within the castle.");
set_exits( ([ "north": "/wizards/powerman/room/fielde4.c",
              "west" : "/wizards/powerman/room/fieldd5.c",
              "east" : "/wizards/powerman/room/foresteasta7.c",]));
}

void reset()
{
 ::reset();
if(query_night() && !present("soldier"))
{
new("/wizards/powerman/arm/macsold")->move(this_object());
new("/wizards/powerman/arm/malsold")->move(this_object());
}
else
if(!present("soldier")) {
new("/wizards/powerman/arm/macsold")->move(this_object());
new("/wizards/powerman/arm/malsold")->move(this_object());
}
}
