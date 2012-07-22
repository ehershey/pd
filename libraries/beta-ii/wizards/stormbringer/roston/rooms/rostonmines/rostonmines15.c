/*  rostonmines
    Created by Stormy
*/

#include <std.h>
#include <rostonmines.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "rostonmines14.c", "south" : ROOMS "rostonmines16.c", "north" : ROOMS "rostonmines17.c"]));
}


