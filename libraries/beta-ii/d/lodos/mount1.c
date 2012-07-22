#include <lodos.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Before the western town gates of Lodos");
    set_long("The western lodos gates stand to the east of this small "
      "mountain overlook. To the west, the Daroq mountains can be seen. "
      "The mountain road leads down the Daroq Mountains.");
    set_items(([ "gates" : "The tall silver gates stand high before you."]));
    set_exits(([ "east" : ROOMS"gates",
	"north" : "/d/coach/rooms/lodos_coach.c",
	"down" : ROOMS"mount2"]));
    set_properties(([ "light" : 2 ]));
    set_property("mountain",1);
}
/*
void reset() {
 ::reset();
   if (!present("guard")) {
      new(MOB"gate_guard")->move(this_object());
      new(MOB"gate_guard")->move(this_object());
   }
}
*/
