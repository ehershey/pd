#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "east"        : ROOMS "lf003.c",
        "south"       : ROOMS "lf001.c",
        "north"       : ROOMS "lf005.c",
        "northwest"   : ROOMS "lf014.c"
    ]) );
}
