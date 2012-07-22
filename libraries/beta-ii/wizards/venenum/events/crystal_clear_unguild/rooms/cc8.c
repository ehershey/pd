#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path by the shore");
    set_long("The path here flanks a cliff, overviewing the ocean, disappearing into the forest to the north. To the southeast, the path hugs the side of the cliff, almost dangerously so. The path is especially gravelly here.");
    set_listen("default", "The sound of the ocean is heard here.");
    set_smell("default", "The air is fresh and crisp.");

    set_items(([
	({"ocean", "sea", "water"}) : "The ocean is a soft blue, sparkling softly.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc6.c",
	"southeast" : ROOMS"ccd.c",
      ]));
}
