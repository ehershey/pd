/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest8.c", "southeast" : ROOMS "tiruneastforest10.c", "east" : ROOMS "tiruneastforest31.c", "northeast" : ROOMS "tiruneastforest35.c"]));
}


