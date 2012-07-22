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
	set_day_long("The air is fresh here, a slight breeze blows rustling the leaves on the ground. Several old, run down tents can be seen in the clearing. This clearing looks like it has been camped at for a long time");
	set_night_long("Shadows dance strangly in all directions, yet, no sounds can be heard. Even the campfire is silent. The forest has gone silent, the campfire is the only movement that can be seen for sure.");
	set_exits( ([
	"south"  : ROOMS"rascij001.c",
	"north" : ROOMS"rascij006.c",
	]) );
}
