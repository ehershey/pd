#include <std.h>
inherit ROOM;

void create() {
::create();
    set_short("goblin mine shaft");
    set_long("This room seems to be the last that holds minerals.  After "
                "here, the walls are bare, and stripped of the precious "
                "stones.  Although no workers are seen past here, the "
                "tunnel seems to continue east.");
    set_properties(([
        "light" : 2,
        "night light" : 2,
    ]));
    set_exits(([
        "south" : "/wizards/marduk/mine_shaft/ms_room8.c",
        "east" : "/wizards/marduk/mine_shaft/ms_room10.c",
    ]));
}

void reset() {
  ::reset();
    if(!present("goblin"))
  {  new("/wizards/marduk/mine_shaft/worker3.c")->move(this_object());
    new("/wizards/marduk/mine_shaft/worker2.c")->move(this_object());
 }
}
