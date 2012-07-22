#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "south"       : "/d/syntheria/lidelas/rooms/lidelas026.c",
        "northeast"   : ROOMS "lf025.c",
    ]) );
}
