/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest32.c", "east" : ROOMS "tiruneastforest34.c", "north" : ROOMS "tiruneastforest81.c", "south" : ROOMS "tiruneastforest82.c"]));
}


