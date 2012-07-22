#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("goblin mine shaft");
    set_long("You venture further away from civilization, only to find "
                "an abandoned tunnel.  Maybe you should turn back now...");
    set_properties(([
        "light" : 2,
        "night light" : 2,
    ]));
    set_exits(([
        "east" : "/wizards/marduk/mine_shaft/ms_room12.c",
        "west" : "/wizards/marduk/mine_shaft/ms_room10.c",
    ]));
}
