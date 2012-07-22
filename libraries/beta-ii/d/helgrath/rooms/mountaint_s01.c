#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create(){
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Mountain Pass");
    set_long("Rigid, almost deafening winds howl through the pass, carrying stinging frozen rain. "
      "To the north a cabin can barely be made out through the sheet of snow and ice. "
    );
    set_exits(([ "north": ROOMS "mountain01.c",
      "south" : ROOMS "mountaint_s02.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Nothing can be heard over the deafening howl of the wind.");
}
void reset(){
    ::reset();
    if(present("white wolf")) return;
    new(MOB"white_wolf.c")->move(this_object());
    new(MOB"white_wolf.c")->move(this_object());
}
