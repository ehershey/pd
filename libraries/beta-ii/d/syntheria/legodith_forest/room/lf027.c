#include <std.h>
#include <legodith_forest.h>

inherit VIRTUALROOM;

void create() {
    set_server(SERVER);
    ::create();
    set_exits( ([ 
        "northeast"       : ROOMS "lf021.c",
        "southeast"       : ROOMS "lf022.c",
        "west"            : ROOMS "lf028.c",
    ]) );
}
