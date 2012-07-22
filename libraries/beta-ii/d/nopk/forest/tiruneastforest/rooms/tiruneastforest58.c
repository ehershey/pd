/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["north" : ROOMS "tiruneastforest57.c", "southwest" : ROOMS "tiruneastforest59.c", "south" : ROOMS "tiruneastforest66.c"]));
}


