#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"         : ROOMS "lf010.c",
        "south"        : ROOMS "lf012.c",       
        "west"         : ROOMS "lf019.c",
        "up"           : "/d/syntheria/prudash/rooms/prudash014.c",
    ]) );
}
