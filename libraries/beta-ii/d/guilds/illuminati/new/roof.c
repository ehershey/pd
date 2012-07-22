#include <std.h>
#include <guild.h>
inherit ROOM;
void create()
{
::create();
set_properties((["light":3, "town": 1]));
set_name("Illuminati Roof");
set_short("Illuminati Roof");
set_long("%^RESET%^%^ORANGE%^The highest point of the Tower of Light lies here, upon the "
"battlements of the 7th floor. From here you have a great view of the "
"surroundings. The clouds float just above you."); 
set_exits(([
"down"          : ROOMS"illuminati/new/floor6.c"
]));
set_items(([
"clouds"        : "%^BOLD%^%^WHITE%^The clouds float above and all around you. Moving your hand "
"through them you can feel that they are insubstantial. As the wind blows you "
"feel as though you are flying.%^RESET%^", 
"surroundings"  : "%^BOLD%^%^BLUE%^The ocean stretches out around you on all sides. Looking "
"down you can see the base of the tower on a small island. Nothing else can be "
"seen as far as the horizon.%^RESET%^"
]));
}
