#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"        : ROOMS "lf014.c",
        "southwest"   : ROOMS "lf024.c",
        "north"       : ROOMS "lf016.c",
    ]) );
}
