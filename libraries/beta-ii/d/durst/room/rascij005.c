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
	set_day_long("This clearing in the forest is very small, it only holds around 5 tents with very little room to spare. The sky is filled with birds of all types, all going about thier daily tasks.");
	set_night_long("The campfire causes strange figures to appear and disappear, it becomes more and more difficult to decipher what is real, and what isn't. In the darkness, a tent can be made out to the west.");
	set_exits( ([
	"southeast"  : ROOMS"rascij004.c",
	"west" : ROOMS"rascij006.c",
	]) );
}
