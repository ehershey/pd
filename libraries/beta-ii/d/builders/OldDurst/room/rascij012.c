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
	set_day_long("This is the south end of the clearing, to the north a small campfire can be seen. Many tents can be seen scattered around in the clearing, all of them appear to be very old and tattered.");
	set_night_long("To the north is a very dim campfire, in the distance what looks to be tents can be seen in the flickering light. Strange shapes are being cast from the campfire, the shapes look to form some kind of humanoid creature that are dancing around the fire.");
	set_exits( ([
	"west"  : ROOMS"rascij011.c",
	"east" : ROOMS"rascij013.c",
	"south" : ROOMS"rascij018.c",
	"north" : ROOMS"rascij015.c",
	]) );
}
