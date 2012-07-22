/*  rostonmines
    Created by Stormy
*/

#include <std.h>
#include <rostonmines.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "rostonmines10.c", "north" : ROOMS "rostonmines19.c"]));
}


