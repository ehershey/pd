/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northwest" : ROOMS "tiruneastforest39.c", "east" : ROOMS "tiruneastforest41.c", "north" : ROOMS "tiruneastforest75.c"]));
}

