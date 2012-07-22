/*  rostonmines
    Created by Stormy
*/

#include <std.h>
#include <rostonmines.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "rostonmines0.c", "south" : ROOMS "rostonmines2.c", "east" : ROOMS "rostonmines3.c", "north" : ROOMS "rostonmines9.c"]));
}


