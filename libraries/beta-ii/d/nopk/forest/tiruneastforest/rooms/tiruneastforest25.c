/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northwest" : ROOMS "tiruneastforest24.c", "east" : ROOMS "tiruneastforest26.c", "southwest" : ROOMS "tiruneastforest43.c"]));
}


