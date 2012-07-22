#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("goblin mine shaft");
    set_long("The ceiling slopes slightly downwards, and you duck "
		"to keep from bumping your head.");
    set_items(([
	"ceiling" : "It seems to be lower then usually.",
    ]));
    set_properties(([
	"light" : 2,
	"night light" : 2,
    ]));
    set_exits(([
	"south" : "/wizards/marduk/mine_shaft/ms_room4.c",
	"north" : "/wizards/marduk/mine_shaft/ms_room8",
    ]));
}

void reset() {
  ::reset();
    if(!present("monster"))
     {	
new("/wizards/marduk/mine_shaft/supervisor.c")->move(this_object());
	new("/wizards/marduk/mine_shaft/worker2.c")->move(this_object());
     }
}
