#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1]));
set_name("Illuminati Floor 5");
set_short("Illuminati floor 5");
set_long("%^RESET%^%^ORANGE%^The 5th floor of the tower of light. This is where the "
"councilor's rooms are located. Doors to the east and west are "
"marked 'Prator' and 'Loki' respectively.");
set_exits(([
"up"            : ROOMS"illuminati/new/floor6.c",
"down"          : ROOMS"illuminati/new/floor4.c",
"east"          : ROOMS"illuminati/new/aziraphale.c",
"west"          : ROOMS"illuminati/new/loki.c",
"northwest"     : ROOMS"illuminati/new/nwturret5.c",
"northeast"     : ROOMS"illuminati/new/neturret5.c",
"south"         : ROOMS"illuminati/new/abzigal",
]));
}
void init()
{
::init();
add_action("east", "east");
add_action("west", "west");
}

int west()
{
if (this_player()->query_name() == "loki" || wizardp(this_player()))
{
this_player()->move_player(ROOMS"illuminati/new/loki.c");  
write("The door opens before you, "+this_player()->query_cap_name()+".");
return 1;
}
write("The door rejects your passage.");
return 1;
}
int east()
{
if (this_player()->query_name() == "prator" || wizardp(this_player()))
{
this_player()->move_player(ROOMS"illuminati/new/aziraphale.c");
write("The door opens before you, "+this_player()->query_cap_name()+".");
return 1;
}
write("The door rejects your passage.");
return 1;
}
