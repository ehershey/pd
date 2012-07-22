/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest9.c", "east" : ROOMS "tiruneastforest36.c", "northwest" : ROOMS "tiruneastforest45.c"]));
}


