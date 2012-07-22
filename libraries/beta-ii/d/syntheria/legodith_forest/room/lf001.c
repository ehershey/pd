#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "south"       : "/d/syntheria/lidelas/rooms/lidelas019.c",
        "north"       : ROOMS "lf004.c",
        "northeast"   : ROOMS "lf003.c",
    ]) );
}
