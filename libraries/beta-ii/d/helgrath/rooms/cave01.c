#include <std.h>
#include <helgrath.h>

inherit ROOM;
void create() {
    ::create();
    set_properties(([
      "light" : 1,
      "indoors" : 1
    ]));
    set_short("Mountain Cave");
    set_long("Walls of ice surround you. Jagged icicles hang precariously from the reflective roof "
      "of the cave. To the north, the way is unclear, being concealed by the deep shadows "
      "of this lonely warren. The way out to the south, however, is lit brightly from the sun's reflection "
      "upon the pure white snow outside. "
    );
    set_exits( ([ "north" : ROOMS "cave02.c", 
      "south": ROOMS "mountaint_w01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Dripping water can be heard.");
    set_items( ([
        "walls" : "The walls are covered in ice",
        "icicles" : "Water dripping then freezing over time has allowed these to form.",
]));
}

