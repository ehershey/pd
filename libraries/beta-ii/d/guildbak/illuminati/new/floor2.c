#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1]));
set_name("Floor 2");
set_short("Illuminati Floor 2");
     set_long("%^RESET%^%^ORANGE%^The second floor of the tower of light. On this floor there "
"%^RESET%^%^ORANGE%^several shops and the guild treasury. There are also open "
"%^RESET%^%^ORANGE%^balconies to the northeast and northwest.");
set_exits(([
"down"          : ROOMS"illuminati/new/newhall.c",
"south"         : ROOMS"illuminati/treasury.c",
"southwest"     : ROOMS"illuminati/new/stoneshop.c",
"southeast"     : ROOMS"illuminati/new/itemshop.c",
"west"          : ROOMS"illuminati/new/weapshop.c",
"east"          : ROOMS"illuminati/new/armshop.c",
"northwest"     : ROOMS"illuminati/new/nwturret2.c",
"northeast"     : ROOMS"illuminati/new/neturret2.c",
"up"            : ROOMS"illuminati/new/floor3.c"
]));
}
