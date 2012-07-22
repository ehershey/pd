#include <std.h>
#include <cc.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Dead end");
    set_long("The path here stops abruptly, destroyed by a recent landslide. There is no way to progress to the southeast via this route.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is fresh and crisp.");

    set_items(([
	({"landslide"}) : "It appears the cliff gave way, destroying the path.",
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"northwest" : ROOMS"cc16.c",
      ]));
}
