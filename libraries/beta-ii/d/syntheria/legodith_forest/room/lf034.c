#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"              : ROOMS "lf029.c",
        "northeast"         : ROOMS "lf028.c",
        "south"             : ROOMS "lf033.c",
    ]) );
}
