//  Created by Whit
#include <std.h>
#include <citrin.h>
inherit ROOM;

void create() {
    ::create();
    set_invis_exits(({"west"}));
    set_name("lost in a forest");
    set_short("lost in a forest");
    set_long("The darkness overtakes the light causing darkness "
      "to overtake the forest.  The directions seem to swirl "
      "and disappear in the everlasting darkness.");
    set_items(([]));
    set_exits(([
	"west":ROOMS"5",
      ]));
    set_properties((["light":1,"night light":1,"forest":1,]));
}

void reset() {
    ::reset();
    if (children(MON"guardian.c")==({}) ||
      sizeof(children(MON"guardian.c"))==0) new(MON"guardian")->move(this_object());
}

