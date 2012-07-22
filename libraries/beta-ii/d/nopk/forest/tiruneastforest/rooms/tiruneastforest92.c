/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "tiruneastforest91.c", "north" : ROOMS "tiruneastforest68.c", "northeast" : ROOMS "tiruneastforest102.c"]));
}


