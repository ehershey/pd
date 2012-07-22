#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("goblin mine shaft");
    set_long("The walls here are stripped of all their minerals.  No "
                "workers are around.");
    set_properties(([
        "light" : 2,
        "night light" : 2,
    ]));
    set_exits(([
        "east" : "/wizards/marduk/mine_shaft/ms_room11.c",
        "west" : "/wizards/marduk/mine_shaft/ms_room9.c",
    ]));
}
