#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "west"         : ROOMS "lf017.c",
        "southeast"    : ROOMS "lf006.c",       
        "northeast"    : ROOMS "lf012.c",

    ]) );
}
