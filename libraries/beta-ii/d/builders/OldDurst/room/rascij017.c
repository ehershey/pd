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
	set_day_long("This is near the center of this clearing, to the east is a small campfire. The campfire looks like it has not been tended to for a while. The rustling of the leaves by the wind can be hard from all directions.");
	set_night_long("The forest has turned into a void of black. Only a campfire to the east emits any light. The fire creates strange illusions that seem to dance in circles.");
	set_exits( ([
	"west"  : ROOMS"rascij009.c",
	"east" : ROOMS"rascij001.c",
	]) );
}

