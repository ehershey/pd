/*  rostonmines
    Created by Stormy
*/

#include <std.h>
#include <rostonmines.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "rostonmines9.c", "west" : ROOMS "rostonmines11.c", "east" : ROOMS "rostonmines12.c", "north" : ROOMS "rostonmines18.c"]));
}


