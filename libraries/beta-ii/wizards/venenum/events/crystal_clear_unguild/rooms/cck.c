#include <std.h>
#include <cc2.h>
inherit ROOM;
inherit "/wizards/venenum/events/message.c";

void create() {
    ::create();
    set_short("Hidden alcove");
    set_long("This tiny alcove doesn't appear to serve any function. It may have been an abandoned tunnel, a storage area or something else completely.");
    set_listen("default", "There is little sound here.");
    set_smell("default", "The air is very musty.");
    set_items(([
      ]));


    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"east" : ROOMS"cci.c",
      ]));
}
void reset()

{

    if (!present("key2")) {
	new(ITEM"key2.c")->move(this_object());
    }
}
