#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"        : ROOMS "lf007.c",
        "southwest"   : ROOMS "lf014.c",
        "northwest"   : ROOMS "lf013.c",
        "south"       : ROOMS "lf005.c",
    ]) );
}
