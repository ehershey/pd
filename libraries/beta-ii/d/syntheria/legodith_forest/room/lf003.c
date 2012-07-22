#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "west"        : ROOMS "lf004.c",
        "southwest"   : ROOMS "lf001.c",
    ]) );
}
