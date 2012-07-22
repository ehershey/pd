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
	set_day_long("This is the far western edge of the clearing, a single tent has been set up here. A small pile of firewood has been neatly stacked right behind the tent.");
	set_night_long("The ground seems to sink slightly here. Many strange figures dance near the campfire, none seem like they are really there. A tent has been put up, it seems to be very old.");
	set_items(([
	   "tent"  : "A very weathered tent.",
	]));
	set_exits( ([
	"north"  : ROOMS"rascij008.c",
	"south"  : ROOMS"rascij010.c",
	"east" : ROOMS"rascij017.c",
	"enter" : ROOMS"rascij022.c",
	]) );
}
void reset() {
   ::reset();
if (!present("camper", this_object()))
     new(MOB"camper.c")->move(this_object());
if (children(MOB"shadow.c")==({})||
     sizeof(children(MOB"shadow.c"))<3)
     new(MOB "shadow")->move(this_object());
}
