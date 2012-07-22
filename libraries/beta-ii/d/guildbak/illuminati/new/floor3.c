#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1]));
set_name("Floor 3");
set_short("Illuminati Floor 3");
set_long("%^RESET%^%^ORANGE%^The third floor of the Tower of Light. Here is where the "
"%^RESET%^%^ORANGE%^prayer and portal rooms are located, as well as the guild "
"%^RESET%^%^ORANGE%^lockers. Two doors open to the northern balconies."); 
set_exits(([
"down"          : ROOMS"illuminati/new/floor2.c",
"southeast"     : ROOMS"illuminati/new/mainportal.c",
"southwest"     : ROOMS"/illuminati/lockeri", 
"west"          : ROOMS"illuminati/new/scry.c",
"east"          : ROOMS"illuminati/new/prayer.c",
"northwest"     : ROOMS"illuminati/new/nwturret3.c",
"northeast"     : ROOMS"illuminati/new/neturret3.c",
"up"            : ROOMS"illuminati/new/floor4.c"
]));
}
