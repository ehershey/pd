#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through the Woodlands");
    set_long("This path leads through slightly dense woodlands, the trees here mostly packed around the path. To the east, the ocean is visible between gaps in the trees- sparkling light shining from the water. The path here is narrow and thin, the ground littered by twigs and leaves.");
    set_listen("default", "The distant sound of the ocean is heard in the distant east.");
    set_smell("default", "The air is fresh and crisp.");

    set_items(([
	({"ocean", "sea", "water"}) : "The ocean is a fair distance away, although it sure looks nice right now.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc4.c",
	"south" : ROOMS"cc8.c",
      ]));
}
