#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":2, "indoors":1]));
set_name("Illuminati Gate Room");
set_short("Illuminati Gate Room");
set_long("%^RESET%^%^ORANGE%^In the middle of the room stands a massive golden archway, inside it "
"is what looks to be a vertical silver shimmering lake. The arch acts as a gate"
"between halls of the Illuminati.");
set_exits(([
"northwest"         : ROOMS"illuminati/new/floor3.c"
]));
}

void reset()
{
::reset();
}
