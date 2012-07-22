#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "southeast"   : ROOMS "lf018.c",
        "southwest"   : ROOMS "lf027.c",
        "northeast"   : ROOMS "lf020.c"
    ]) );
}
