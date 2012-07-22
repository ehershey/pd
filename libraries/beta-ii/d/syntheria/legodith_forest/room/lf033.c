#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "north"             : ROOMS "lf034.c",
        "northeast"         : ROOMS "lf029.c",
        "south"             : ROOMS "lf032.c",
    ]) );
}
