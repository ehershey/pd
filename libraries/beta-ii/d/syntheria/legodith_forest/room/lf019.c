#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"        : ROOMS "lf011.c",
        "southeast"   : ROOMS "lf012.c",
        "northwest"   : ROOMS "lf020.c",
        "southwest"   : ROOMS "lf018.c"
    ]) );
}
