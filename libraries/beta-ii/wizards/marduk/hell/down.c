#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("down to hell");
    set_long("2nd room of hell");
    set_items(([
	"hell" : "This is hell",
    ]));
    set_properties(([
	"light" : 2,
    ]));
    set_exits(([
	"up" : "/wizards/marduk/hell/h_room1.c",
    ]));
}
