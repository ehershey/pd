/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest63.c", "northeast" : ROOMS "tiruneastforest65.c", "southeast" : ROOMS "tiruneastforest88.c"]));
}


