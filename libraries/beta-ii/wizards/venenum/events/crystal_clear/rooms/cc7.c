#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Path through the Woodlands");
    set_long("The path here is narrow and tight, leaving very little room to move in. The path below is heavily overgrown with thorny vines and small bushes, although it is still distinct through the trees. It would appear nobody has been along this part of the path for a very long time.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is fresh and crisp.");

    set_items(([
	({"path"}) : "The path is almost dangerous to walk upon because of the thorns.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"cc5.c",
	"south" : ROOMS"cch.c",
      ]));
}
