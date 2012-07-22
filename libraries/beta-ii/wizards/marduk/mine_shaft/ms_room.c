#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("an old mine shaft");
    set_long("This is the entrance to an old Goblin mine shaft. "
		" The mine looks like it could cave in at any moment. "
		"You better take precaution as you enter.");
    set_items(([
	"shaft" : "The shaft looks extremely unstable.",
    ]));
    set_properties(([
	"light" : 2,
	"night light" : 2,
    ]));
    set_exits(([
	"mine" : "/wizards/marduk/mine_shaft/ms_room2.c",
        "east" : "/d/standard/spass5",
        "west" : "/d/standard/spass7",
    ]));
}

void reset() {
  ::reset();
    if(!present("goblin"))
	new("/wizards/marduk/mine_shaft/worker.c")->move(this_object());
}
