/*  rostonmines
    Created by Stormy
*/

#include <std.h>
#include <rostonmines.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["north" : ROOMS "rostonmines1.c"]));
}


