/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northwest" : ROOMS "tiruneastforest48.c", "east" : ROOMS "tiruneastforest63.c", "southwest" : ROOMS "tiruneastforest97.c"]));
}


