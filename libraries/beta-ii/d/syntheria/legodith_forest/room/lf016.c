#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "west"        : ROOMS "lf023.c",
        "south"       : ROOMS "lf015.c",
        "north"       : ROOMS "lf017.c",
        "up"          : "/d/syntheria/prudash/rooms/prudash010.c",
    ]) );
}
