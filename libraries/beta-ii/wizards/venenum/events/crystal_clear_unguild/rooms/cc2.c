#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path south of the Halfling camp");
    set_long("The clearing to the north elongates into a path here, forking into two directions, a thin path to the southwest and a larger path to the southeast. Tall trees surround this pathway, making straying from it difficult. A trail of blood leads to the north and the southeast along with some fresh tracks.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The faint smell of burning fabric comes from the north.");

    set_items(([
	({"path"}) : "The path leads to the north, the southwest and the southeast.",
	({"trail", "blood"}) : "The trail is not overly strong, although it appears to be a mixture of blood from two different races- the light red blood of halflings and an unknown, darker blood, almost black in colour and smelling strongly of mercury.",
	({"tracks", "track"}) : "The tracks are fresh and made by booted feet. Despite the number of boots, possibly up to six or seven, the tracks are surprisingly light and almost elvish in nature.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc1.c",
	"southeast" : ROOMS"cc4.c",
	"southwest" : ROOMS"ccm.c",
      ]));
}
