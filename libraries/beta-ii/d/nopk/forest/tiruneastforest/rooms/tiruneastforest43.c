/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest42.c", "northeast" : ROOMS "tiruneastforest25.c", "southeast" : ROOMS "tiruneastforest93.c"]));
}


