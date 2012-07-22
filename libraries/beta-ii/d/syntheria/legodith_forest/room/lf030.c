#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "west"            : ROOMS "lf032.c",
        "southeast"       : ROOMS "lf025.c",
        "northeast"       : ROOMS "lf026.c",
    ]) );
}
