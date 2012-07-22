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
      "winds. The sleet raining down in thick sheets is almost blinding. " );
    set_exits(([ "north": ROOMS "mountaint_s01.c",
      "east" : ROOMS "mountaint_s03.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Nothing can be heard over the deafening howl of the wind.");
}
void reset(){
    ::reset();
    if(present("white wolf")) return;
    new(MOB"white_wolf.c")->move(this_object());
}
