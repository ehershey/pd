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
	set_day_long("This is the far north end of the clearing, a solitary tent is set up here. A pile of wood has been stacked neatly next to the tent, likley for the campfire to the south.");
	set_night_long("A small light can be seen coming from the tent here, likley from a small candle inside. Strange shadows fly around in every direction.");
	set_exits( ([
	"south"  : ROOMS"rascij016.c",
	"west" : ROOMS"rascij007.c",
	"east" : ROOMS"rascij005.c",
	"enter" : ROOMS"rascij021.c",
	]) );

}
void reset() {
   ::reset();
if (!present("camper", this_object()))
     new(MOB"camper.c")->move(this_object());
}
