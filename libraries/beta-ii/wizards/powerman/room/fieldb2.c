#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The battlefields");
set_day_long("Swords clashing, People screaming. The ground is trampled and
dirty. You are closer Macbeth's castle in the far south. You are approaching
the important location of the battlefield, the top of the gentle hill in the
southeast. Corpses litter the ground. Within the thick smog of dust, you see
reflections of sunlight off the weapons and armour of the soldiers in the
battle.");
set_night_long("The battle rages on even deep into the night. There are fires
from destruction everywhere. Sword sparks make the battlefield seem like the
dark clear sky. You can't help but feel that you are stepping on corpses on the
ground. You see are closer to the castle of Macbeth in the far south. ");
set_items(([
"ground" : "Trampled and dirty.",
"sunlight"     : "Where else do you look for sunlight?",
"reflections" : "The sunlight bounces off of the armour and swords of the soldiers.",

]));
set_smell("default","The Smell of blood and sweat is intense.");
set_listen("default","Swords clashing is echoed by soldiers screaming.");
set_exits( ([ "north": "/wizards/powerman/room/fieldb1.c",
              "west" : "/wizards/powerman/room/fielda2.c",
              "south": "/wizards/powerman/room/fieldb3.c",
              "east" : "/wizards/powerman/room/fieldc2.c",]));
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
