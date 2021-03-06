#include <std.h>
#include <durst.h>
inherit ROOM;
void create() {
   ::create();
	set_name("Rascij");
	set_short("Small Camp");
	set_properties(([
        "light"       : 2,        
        "night light" : 1,
        ]));
	set_day_long("The clearing becomes very dense here, becoming more part of the forest then the clearing. Small forest animals can be heard running around the forest floor, more then likley gathering food.");
	set_night_long("It is very dark in this part of clearing, a few of the trees block the campfire. The forest becomes a void, almost completly dark except for a few flickers of light from the campfire.");
	set_exits( ([
	"south"  : ROOMS"rascij009.c",
	"northeast" : ROOMS"rascij007.c",
	]) );
}
