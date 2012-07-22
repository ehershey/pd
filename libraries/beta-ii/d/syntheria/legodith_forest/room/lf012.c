#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"         : ROOMS "lf009.c",
        "southwest"    : ROOMS "lf013.c",       
        "northwest"    : ROOMS "lf019.c",
        "north"        : ROOMS "lf011.c",
    ]) );
}
