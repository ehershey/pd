#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "indoors":1]));
set_name("Illuminati Floor 6");
set_short("Illuminati floor 6");
set_long("%^RESET%^%^ORANGE%^The 6th and final floor of the tower of light. This is where "
"the Leader's personal room is located. There is one door "
"leading south with the word 'Halo' burned into it. Stairs "
"lead up to the roof. ");
set_exits(([
"up"            : ROOMS"illuminati/new/roof.c",
"down"          : ROOMS"illuminati/new/floor5.c",
"south"         : ROOMS"illuminati/new/halo.c",
"northwest"     : ROOMS"illuminati/new/nwturret6.c",
"northeast"     : ROOMS"illuminati/new/neturret6.c"
]));
}
void init()
{
::init();
add_action("south", "south");
}

int south()
{
 if (GUILD_D->query_guild(this_player()->query_name()) == "illuminati" || wizardp(this_player()))
{
this_player()->move_player(ROOMS"illuminati/new/halo.c");  
write("The door opens before you, "+this_player()->query_cap_name()+".");
return 1;
}
write("The door rejects your passage");
return 1;
}
