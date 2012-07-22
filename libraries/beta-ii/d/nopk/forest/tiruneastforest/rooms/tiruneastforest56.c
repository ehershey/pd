/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest55.c", "southeast" : ROOMS "tiruneastforest57.c", "southwest" : ROOMS "tiruneastforest61.c"]));
}


