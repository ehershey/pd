#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "southeast"   : ROOMS "lf019.c",
        "southwest"   : ROOMS "lf021.c"
    ]) );
}
