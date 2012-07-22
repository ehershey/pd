#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "north"        : ROOMS "lf010.c",
        "south"        : ROOMS "lf008.c",       
        "west"         : ROOMS "lf012.c",
    ]) );
}
