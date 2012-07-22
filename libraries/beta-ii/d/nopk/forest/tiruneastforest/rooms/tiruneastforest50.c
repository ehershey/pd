/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "tiruneastforest49.c", "north" : ROOMS "tiruneastforest51.c", "southwest" : ROOMS "tiruneastforest78.c"]));
}


