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
	set_day_long("This would appear to be the center of a small camp ground. A few tattered tents are set up in a circle around a fading fire. The forest surrounding the camp is alive with activity. Birds can be seen in the sky, small rodents running around, and even a few deer can be seen in the distance.");
	set_night_long("This would appear to be the center of a small camp ground. A few tattered tent are set up in a circle around a roaring fire. The forest creates strange shadows with the light from the campfire, a deafening silence comes from the black void of the forest.");
	 set_items(([
        "campfire" : "The campfire looks like it has been used for many nights and days.",
	"tents"    : "These old tattered tents look like they have weathered much."
        ]));
 	set_smell("default", "The smell of smoke fills the air");
	set_exits( ([
        "south" : ROOMS"rascij015.c",
	"east"  : ROOMS"rascij002.c",
	"north" : ROOMS"rascij016.c",
	"west"  : ROOMS"rascij017.c",
	 ]) );
}

void reset() {
   ::reset();
if (!present("camper", this_object()))
     new(MOB"camper.c")->move(this_object());
}

