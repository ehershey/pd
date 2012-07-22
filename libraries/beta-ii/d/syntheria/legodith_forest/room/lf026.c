#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "northwest"       : ROOMS "lf029.c",
        "southwest"       : ROOMS "lf030.c",
        "east"            : ROOMS "lf023.c",
    ]) );
}
