#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("goblin mine shaft");
    set_long("You are near the end of the tunnel, and the light starts "
                "fade.  The tunnel is damp, and you wonder how the goblins "
                "can stand these conditions.");
    set_items(([
        "light" : "The light is starting to fade...",
    ]));
    set_properties(([
        "light" : 2,
        "night light" : 1,
    ]));
    set_exits(([
        "south" : "/wizards/marduk/mine_shaft/ms_room6.c",
        "north" : "/wizards/marduk/mine_shaft/ms_room9.c",
    ]));
}

void reset() {
  ::reset();
    if(!present("goblin"))
 {    new("/wizards/marduk/mine_shaft/worker3.c")->move(this_object());
    new("/wizards/marduk/mine_shaft/worker2.c")->move(this_object());
 }
}
