#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("a secret room");
    set_long("%^BOLD%^%^BLACK%^You are in a secret room hidden by shadows.");
    set_items(([
	"shadows" : "Deep in the shadows reveal an exit north.",
    ]));
    set_properties(([
	"light" : 1,
    ]));
    set_exits(([
	"north" : "/wizards/marduk/hell/h_room9.c",
    ]));
    add_invis_exit("north");
}

void reset() {
    if(!present("salazar"))
	new("/wizards/marduk/hell/salazar.c")->move(this_object());
}
