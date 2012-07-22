#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "north"       : ROOMS "lf008.c",
        "west"        : ROOMS "lf006.c",
        "up"          : "/d/syntheria/prudash/rooms/prudash017.c",
        
    ]) );
}
