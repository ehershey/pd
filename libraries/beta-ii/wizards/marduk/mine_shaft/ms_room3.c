#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("an old mine shaft");
    set_long("You venture farther into the mine shaft. "
                "Torches hang on the walls to light the tunnel, "
                "and workers continue digging along the walls.");
    set_properties(([
        "light" : 2,
        "night light" : 2,
    ]));
    set_exits(([
        "north" : "/wizards/marduk/mine_shaft/ms_room4.c",
        "east" : "/wizards/marduk/mine_shaft/ms_room5.c",
"south" : "/wizards/marduk/mine_shaft/ms_room2.c",
    ]));
}

void reset() {
 ::reset(); 
    if(!present("goblin"))
     {
        new("/wizards/marduk/mine_shaft/worker2.c")->move(this_object());
        new("/wizards/marduk/mine_shaft/worker2.c")->move(this_object());
     } 
}

