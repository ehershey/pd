/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southeast" : ROOMS "tiruneastforest69.c", "northwest" : ROOMS "tiruneastforest71.c", "northeast" : ROOMS "tiruneastforest85.c"]));
}


