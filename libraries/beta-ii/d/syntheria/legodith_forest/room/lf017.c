#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"        : ROOMS "lf013.c",
        "south"       : ROOMS "lf016.c",
        "north"       : ROOMS "lf018.c",
    ]) );
}
