#include <std.h>
#include <guild.h>
inherit ROOM;
void init() 
{
::init();
add_action("up", "south");
}

void create() 
{
::create();
set_properties((["light":2, "town":1]));
set_name("Illuminati Entrance");
set_short("Illuminati Entrance");
set_long("The tower of light stands before you, it's white walls "
"reaching all the way to the clouds. Balconies hang off each "
"floor providing an excellent view of the city. A large gate "
"bars entry to the uninitiated.");
set_exits(([
"north"         : ROOMS"illuminati/new/beach",
"south"            : ROOMS"illuminati/new/newhall.c"
]));
set_items(([
"tower"         : "It's pure white walls reach all the way to the clouds, the from the top must be amazing.",
"balconies"     : "Two balconies lead off each floor, one to the northwest of the tower, and another to the northeast.",
"gate"          : "The gate will only open for those initiated into the ranks of the illuminati."
]));
}

int up()
{
object tp;
tp = this_player();
if (tp->query_guild() != "illuminati" && !wizardp(tp))
{
message("info", "%^RESET%^%^CYAN%^A shadow says:%^RESET%^ You are not welcome here!", environment(tp), );
message("info", "%^BOLD%^%^WHITE%^A blinding light %^YELLOW%^consumes%^WHITE%^ "+tp->query_cap_name()+"!%^RESET%^",
environment(tp), tp);
write("%^BOLD%^%^WHITE%^A blinding light %^YELLOW%^consumes %^WHITE%^you!%^RESET%^");
tp->add_hp(-5);
tp->add_sp(-5);
tp->add_mp(-5);
write("hp: "+tp->query_hp()+"   sp: "+tp->query_sp()+"   mp: "+tp->query_mp()+"");
return 1;
}
write("The gates swing open, allowing you entry to the Tower of Light.");
message("info", "The gates swing open, allowing "+tp->query_cap_name()+" entry
to the Tower of Light.", environment(tp), tp);
tp->move_player(ROOMS"illuminati/new/newhall.c");
return 1;
}
