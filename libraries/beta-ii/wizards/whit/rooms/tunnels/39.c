#include <std.h>
#include <forgotten.h>

inherit TUNNEL;

void create() {
    ::create();
    set_exits( ([ 
        "west":TUNNELS"37",
//        "east":TUNNELS"39",
        "south":TUNNELS"40",
      ]) );
}

