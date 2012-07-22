#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("A dead end");
    set_long("The passage ends abruptly here. There is little of note here apart from flat stone- the path of the water which carved out this tunnel changed eons ago and this tiny passage is all that is left.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is a little musty.");
    set_items(([
      ]));

    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"northwest" : ROOMS"cc24.c",
      ]));
}
