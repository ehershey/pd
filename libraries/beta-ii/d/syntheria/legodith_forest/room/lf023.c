#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "north"       : ROOMS "lf022.c",
        "west"        : ROOMS "lf026.c",
        "east"        : ROOMS "lf016.c"
    ]) );
}
