#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("goblin mine shaft");
    set_long("You walk further and further into this mess. The flesh of "
      "the corpses here has started to rot and bone shows through the "
      "rotting flesh of some corpses.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"east" : "/wizards/marduk/mine_shaft/ms_room14.c",
	"west" : "/wizards/marduk/mine_shaft/ms_room12.c",
      ]));
}

void reset() {
    ::reset();
    if(!present("bat"))
	new("/wizards/marduk/mine_shaft/bat.c")->move(this_object());
}
