/*  rostonmines
    Created by Stormy
*/

#include <std.h>
#include <rostonmines.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "rostonmines13.c", "east" : ROOMS "rostonmines15.c"]));
}


