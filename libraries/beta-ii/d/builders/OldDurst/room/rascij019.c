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
	set_day_long("This is in the middle of a large, dense forest. All directions look the same, the only difference is to the north, where there may be a clearing. Many birds can be heard flying from tree to tree, nesting and hunting food.");
	set_night_long("The entire forest is black, nothing can be seen in any direction. A slight flicker of light can be seen to the north, but it reveals nothing.");
		set_exits( ([
	"north"  : ROOMS"rascij018.c",
	
	
	]) );
}
