#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"            : ROOMS "lf027.c",
        "south"           : ROOMS "lf029.c",
        "southwest"       : ROOMS "lf034.c",
        "up"              : "/d/syntheria/prudash/rooms/prudash006.c",
    ]) );
}
