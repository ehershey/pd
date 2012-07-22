#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "west"         : ROOMS "lf015.c",
        "east"         : ROOMS "lf005.c",
        "southeast"    : ROOMS "lf004.c",       
        "northeast"    : ROOMS "lf006.c",

    ]) );
}
