/*  rostonmines
    Created by Stormy
*/

#include <std.h>
#include <rostonmines.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "rostonmines18.c", "west" : ROOMS "rostonmines20.c", "east" : ROOMS "rostonmines21.c"]));
}


