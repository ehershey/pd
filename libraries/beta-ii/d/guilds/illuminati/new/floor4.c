#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1]));
set_name("Illuminati Floor 4");
set_short("Illuminati floor 4");
set_long("%^RESET%^%^ORANGE%^The 4th floor of the Tower of Light. In addition to the "
"%^RESET%^%^ORANGE%^northwest and northeast balconies, this floor also holds the "
"%^RESET%^%^ORANGE%^guild's board, as well as the Book of Grudges. Stairs "
"%^RESET%^%^ORANGE%^continue up to the councilor's apartments.");
set_exits(([
"down"          : ROOMS"illuminati/new/floor3.c",
"up"            : ROOMS"illuminati/new/floor5.c",
"northeast"     : ROOMS"illuminati/new/neturret4.c",
"northwest"     : ROOMS"illuminati/new/nwturret4.c",
"southwest"     : ROOMS"illuminati/new/grudges.c",
"southeast"     : ROOMS"illuminati/new/board.c"
]));
}
