/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest7.c", "east" : ROOMS "tiruneastforest9.c", "northwest" : ROOMS "tiruneastforest23.c"]));
}


