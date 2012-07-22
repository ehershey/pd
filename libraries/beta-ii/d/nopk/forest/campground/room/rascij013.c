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
 	set_day_long("This clearing in the forest is very small, only a few tents and a campfire can fit here. Small animals can be seen going about thier buisness on the forest floor.");
	set_night_long("The forest has become a void in the night. Nothing can be seen or heard in the forest, it as if it isn't there. A small campfire can be seen to the northwest, it creates strange shadows");
	set_exits( ([
	"northeast"  : ROOMS"rascij014.c",
	"west" : ROOMS"rascij012.c",
	]) );
}
