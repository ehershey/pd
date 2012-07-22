#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "south"       : ROOMS "lf023.c",
        "northwest"   : ROOMS "lf027.c",
        "northeast"   : ROOMS "lf018.c"
    ]) );
}
