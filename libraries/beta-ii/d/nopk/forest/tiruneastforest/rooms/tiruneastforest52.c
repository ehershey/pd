/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southeast" : ROOMS "tiruneastforest27.c", "northwest" : ROOMS "tiruneastforest11.c", "northeast" : ROOMS "tiruneastforest82.c"]));
}


