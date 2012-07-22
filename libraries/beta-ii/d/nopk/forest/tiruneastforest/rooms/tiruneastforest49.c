/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest48.c", "north" : ROOMS "tiruneastforest50.c", "northeast" : ROOMS "tiruneastforest60.c"]));
}


