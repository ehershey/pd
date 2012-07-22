#include <std.h>
#include <mjungle.h>
inherit ROOM;

void create() {
    ::create();
    set_properties((["light": 2, "night light" : 2, "town" : 1]));
    set_name("Within the Merkkerri Jungle");
    set_short("Within the Merkkerri Jungle");
    set_long("You are in the Merkkirri Jungle.  The jungle is thick and full "
      "of life.  Bugs hover near you waiting for a snack and the humid air clings "
      "to you making this a very unpleasant place to be.  Sounds of dripping water "
      "can be heard as the leaves of the plants and trees are soaked " 
      "in moisture.");
    set_exits(([
	"north"          : MJUNGLE"mjungle8.c",
	"east"          : MJUNGLE"mjungle1.c",
      ]));
}
void reset() {
    ::reset();
    if(!present("black panther")) {
	new(MOB "panther")->move(this_object());
	new(MOB "panther")->move(this_object());
    }
}
