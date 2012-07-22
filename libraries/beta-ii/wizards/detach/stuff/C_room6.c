#include <std.h>
inherit ROOM;
void create() {
::create();
    set_short("end of a tunnel");
    set_long("Just as you come around the corner, the tunnel comes to "
             "a sudden end. Long ago the tunnel may have continued, "
             "but after years of change, there is only a dead end here. "
             "The path only leads back to the east.");
    set_items(([
        "walls" : "The walls are covered with cobwebs and dust.",
        "ground" : "The ground is a hard granite floor that "
	           "that seems to be covered with dust."]) );
   set_property("light", 1);
 set_exits(([
     "east" : "/wizards/detach/C_room3.c"
      ]));
}

void reset() {
 ::reset();
   if(!present("male"))
    new("/wizards/detach/mspider")->move(this_object());
}
