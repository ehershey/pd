#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("goblin mine shaft");
    set_long("You notice fresh limbs and corpses rotting all over the "
      "room.  It must have taken a monster to do this...");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"east" : "/wizards/marduk/mine_shaft/ms_room13.c",
	"west" : "/wizards/marduk/mine_shaft/ms_room11.c",
      ]));
}

void reset() {
    ::reset();
    if(!present("bat"))
	new("/wizards/marduk/mine_shaft/bat.c")->move(this_object());
}
