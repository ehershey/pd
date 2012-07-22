#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "west"            : ROOMS "lf034.c",
        "north"           : ROOMS "lf028.c",
        "southwest"       : ROOMS "lf033.c",
        "southeast"       : ROOMS "lf026.c",
    ]) );
}
