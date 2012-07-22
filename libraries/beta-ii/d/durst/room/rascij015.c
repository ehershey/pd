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
	set_day_long("This place is just south of the small campfire, several old tents have been set up around the fire. Leaves are scattered all across the ground, this clearing is not very well tended.");
	set_night_long("The campfire makes seeing the surrounding forest virtually impossible. Strange shapes move in all directions, the shapes seem to form into humanoid creatured, but then vanish just as quickly");
	set_exits( ([
	"south"  : ROOMS"rascij012.c",
	"north" : ROOMS"rascij001.c",
	]) );
}
