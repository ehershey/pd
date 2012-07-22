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
	set_day_long("This is the eastern edge of the clearing, a tent can be seen to the south. It appears to be tattered and old, it looks to have been there a long time. The trees sway in the wind, the ruslting of leaves can be heard in all directions.");
	set_night_long("The camp is hard to see in the dark, the campfire creates strange shadows that seem to dance in the void. No sounds come from the forest, it seems like all life ends when the sun goes down.");
	set_exits( ([
	"south"  : ROOMS"rascij003.c",
	"northwest" : ROOMS"rascij005.c",
	]) );
}
