#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "northeast"       : ROOMS "lf015.c",
        "west"            : ROOMS "lf025.c",
    ]) );
}
