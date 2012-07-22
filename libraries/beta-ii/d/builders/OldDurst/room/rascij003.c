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
	set_day_long("A single small tent is set up here. Small forest animals can be seen climbing trees, and feeding on the various grasses of the forest. A soft breeze blows through the trees.");
	set_night_long("A single small tent is set up here. Strange shadows are cast on the tent from the campfire. The forest is pure black, nothing can be seen past the camp.");
	set_properties(([
        "light"       : 2,        
        "night light" : 1,
        ]));
  	set_items(([
        "tents"    : "These old tattered tents look like they have weathered much."
        ]));
	set_exits( ([
	"west"  : ROOMS"rascij002.c",
	"north"  : ROOMS"rascij004.c",
	"south"  : ROOMS"rascij014.c",
	"enter"  : ROOMS"rascij024.c"
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
