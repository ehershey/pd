/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest64.c", "north" : ROOMS "tiruneastforest66.c", "northeast" : ROOMS "tiruneastforest67.c"]));
}


