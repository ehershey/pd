#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "north"            : ROOMS "lf032.c",
        "up"              : "/d/syntheria/prudash/rooms/prudash001.c",
    ]) );
}
