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
	set_day_long("Small tents have been set up all around here in a tiny clearing in the forest. Dozens of small birds fly over head, each with thier own unique tune. Every leaf on every tree dances in the wind, the whole forest is alive with activity");
	set_night_long("Small tents have been set up all around here in a tiny clearing in the forest. The forest is silent, the only sounds that cam be heard are from a small campfire to the west. The forest looks like a dark void, ready to eat anything that gets too close");
	set_items(([
        "tents"    : "These old tattered tents look like they have weathered much."
        ]));
	set_smell("default", "The smell of smoke fills the air");
	set_exits( ([
	"west"  : ROOMS"rascij001.c",
	"east"  : ROOMS"rascij003.c"
	]) );
}
