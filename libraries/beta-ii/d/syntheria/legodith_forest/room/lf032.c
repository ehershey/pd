#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "north"             : ROOMS "lf033.c",
        "east"              : ROOMS "lf030.c",
        "south"             : ROOMS "lf031.c",
    ]) );
}
