#include <roston.h>
#include <std.h>
inherit ROOM;
void create() {
::create();
    set_short("a dead end passageway");
    set_long("You have arrived at a small dead end. Huge stalagmites "
             "block every direction but the way you came. The rock "
             "formations down here must have taken forever to form!");
    set_items(([
        "walls" : "The walls are covered with cobwebs and dust.",
        "ground" : "The ground is a hard granite floor that "
	           "that seems to be covered with dust."]) );
  set_property("light", 1);
  set_exits(([
     "east" : ROOMS"C_room1.c"
      ]));
}

void reset() {
/*
     if(!present("female"))
 new("/wizards/detach/fspider")->move(this_object());
*/
}
