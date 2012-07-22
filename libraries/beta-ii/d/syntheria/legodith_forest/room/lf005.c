#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "west"        : ROOMS "lf014.c",
        "south"       : ROOMS "lf004.c",
        "north"       : ROOMS "lf006.c",
    ]) );
}
