#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "north"        : ROOMS "lf009.c",
        "south"        : ROOMS "lf007.c",       
    ]) );
}
