#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("goblin mine shaft");
    set_long("This is the end of the tunnel. All that remains are bare "
      "walls and piles of bones.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"west" : "/wizards/marduk/mine_shaft/ms_room13.c",
      ]));
}

void reset() {
    ::reset();
    if(!present("bat"))
	new("/wizards/marduk/mine_shaft/bat.c")->move(this_object());
}
