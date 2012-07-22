#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create(){
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mountain Pass");
    set_long("The pass through the mountains boasts knee-deep snow and frigid, stinging "
      "winds. Thick, dark clouds cover the sky. " );
    set_exits(([ "west": ROOMS "mountaint_s02.c",
      "east" : ROOMS "mountaint_s04.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Nothing can be heard over the deafening howl of the wind.");
}
