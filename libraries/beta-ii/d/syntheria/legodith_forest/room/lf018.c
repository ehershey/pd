#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "northeast"   : ROOMS "lf019.c",
        "south"       : ROOMS "lf017.c",
        "northwest"   : ROOMS "lf021.c",
        "southwest"   : ROOMS "lf022.c"
    ]) );
}
