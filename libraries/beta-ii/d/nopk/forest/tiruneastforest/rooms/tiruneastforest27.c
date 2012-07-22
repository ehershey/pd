/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest26.c", "northeast" : ROOMS "tiruneastforest28.c", "northwest" : ROOMS "tiruneastforest52.c", "east" : ROOMS "tiruneastforest77.c"]));
}


