#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("goblin mine shaft");
    set_long("The tunnel is heated and stuffy.  Large diamonds jut "
		"from the ceiling.  You better be quiet or they may all "
		"fall down.");
    set_items(([
	"diamonds" : "They look ready to fall any minute...",
    ]));
    set_properties(([
	"light" : 2,
	"night light" : 2,
    ]));
    set_exits(([
	"south" : "/wizards/marduk/mine_shaft/ms_room3.c",
	"north" : "/wizards/marduk/mine_shaft/ms_room6.c",
	"west" : "/wizards/marduk/mine_shaft/ms_room7.c",
    ]));
}

void reset() {
   ::reset();
    if(!present("goblin"))
    {
    new("/wizards/marduk/mine_shaft/worker3.c")->move(this_object());
	new("/wizards/marduk/mine_shaft/worker3.c")->move(this_object());
    }
}
