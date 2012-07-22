#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "south"        : ROOMS "lf009.c",       
        "west"         : ROOMS "lf011.c",
    ]) );
}
