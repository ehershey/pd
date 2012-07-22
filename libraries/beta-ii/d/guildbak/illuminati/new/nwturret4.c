#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_name("Illuminati NW Turret");
set_short("The Northwestern Turret.");
set_day_long("%^RESET%^%^ORANGE%^This is the northwestern turret of the Illuminati tower. The "
"floor is made of stone blocks rather than the marble of inside, and they show "
"signs of wear. From this vantage point you can see the the ocean all around.");
set_night_long("%^RESET%^%^ORANGE%^The northwestern turret of the Illuminati tower. Torches are "
"lit along the tower wall to provide light. In the night sky you can see lights "
"far to the north.");
set_items(([
"ocean"         : "%^BOLD%^%^BLUE%^The ocean surrounds the Tower of Light on all sides.%^RESET%^",
"floor"         : "The stone blocks have been worn smooth by the constant wind and rain.",
"torches"       : "The torches provide light during the night.",
"wall"          : "The walls of the tower seem to be void of wear, and still show their intricate carvings perfectly.",
"lights"        : "The lights seem to come from an island city, though you have never seen one there."
]));
set_listen("default", "Waves crash onto the beach far below.");
set_properties(([
"light"         : 2,
"night light"   : 2,
"town"          : 1 
]));
set_exits(([
"southeast" : ROOMS"illuminati/new/floor4.c"
]));
}
