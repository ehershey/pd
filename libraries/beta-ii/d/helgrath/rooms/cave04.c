#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create(){
    ::create();
    set_properties(([
      "light" : -2,
      "indoors" : 1
    ]));
    set_short("Icey Cave");
    set_long("This small cavern lies barren. A few insects creep along in the crevasses of the room."
    );
    set_exits(([ "south": ROOMS "cave03.c" ]));
    set_smell("default", "It reeks of decaying flesh.");
    set_listen("default", "A faint scratching noise can be heard.");
    set_items( ([
        "insects" : "Even in this frigid cold these creatures thrive.",
]));
}

void reset(){
    ::reset();
    if(present("white wolf")) return;
    new(MOB"white_wolf.c")->move(this_object());
    new(MOB"white_wolf.c")->move(this_object());
}
