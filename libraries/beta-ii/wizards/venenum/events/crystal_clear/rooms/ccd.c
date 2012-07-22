#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("On the edge of a Cliff");
    set_long("This long cliff juts out to the ocean here, curving towards the east, then back towards the south. A trail of blood leads towards the body of a dead halfling warrior, the female shortfolk slumped over a rock. A disturbing amount of light red blood is splashed over the area, indicating a pitched battle, along with a few splatterings of a darker blood, almost black.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The thick smell of blood is strong here.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"south" : ROOMS"cc13.c",
	"northwest" : ROOMS"cc8.c",
      ]));
}

void reset()

{

    if (!present("body")) {
	new(ITEM"dead_halfling.c")->move(this_object());
    }
}
