#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "northwest"       : ROOMS "lf030.c",
        "southwest"       : ROOMS "lf002.c",
        "east"            : ROOMS "lf024.c",
    ]) );
}
