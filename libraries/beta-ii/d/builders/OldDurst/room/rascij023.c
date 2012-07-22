#include <std.h>
#include <durst.h>
inherit ROOM;
void create() {
   ::create();
	set_name("Rascij");
	set_short("Small Camp");
	set_properties(([
        "light"       : 2,        
        "night light" : 2,
	"indoors"     : 1, 
        ]));
	set_long("This is the inside of one of the tattered tents, this tent looks like it only provides minimal protection from the enviroment. It has small holes and rips in it everywhere. It does seem bigger on the inside then it appeared on the outside.");
	set_exits( ([
	"out" : ROOMS"rascij011.c",
	]) );
}

void reset() {
   ::reset();
if (!present("camper", this_object()))
     new(MOB"camper.c")->move(this_object());
if (!present("wife", this_object()))
     new(MOB"campers_wife.c")->move(this_object());
}
