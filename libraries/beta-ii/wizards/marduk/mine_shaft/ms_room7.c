#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("goblin mine shaft");
    set_long("This is a secluded corner of the tunnels.  Lights from "
		"the other rooms create shadows in this unlit corner. "
		"A slacking worker sits here downing booze.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
    ]));
    set_exits(([
	"east" : "/wizards/marduk/mine_shaft/ms_room4.c",
    ]));
}

void reset() {
  ::reset();
    if(!present("goblin"))
	new("/wizards/marduk/mine_shaft/drunk.c")->move(this_object());
}
