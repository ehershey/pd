#include <std.h>
inherit ROOM;
void create() {
::create();
    set_short("a huge cave");
    set_long("The cave twists and turns in seeming circles. The cold "
             "granite is unbearable and seems to be pressing in on you, "
             "trying to smother you. You are starting to become lost.");
    set_items(([
        "walls" : "The walls are covered with cobwebs and dust.",
        "ground" : "The ground is a hard grante floor that "
	           "that seems to be covered with dust."]) );
  set_property("light", 0);
  set_exits(([
     "south" : "/wizards/detach/C_room1.c",
     "west" : "/wizards/detach/C_room6.c"
      ]));
}

void reset() {
     if(!present("male"))
 new("/wizards/detach/mspider")->move(this_object());
}
