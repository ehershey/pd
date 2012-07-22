/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest25.c", "northeast" : ROOMS "tiruneastforest27.c", "southeast" : ROOMS "tiruneastforest46.c"]));
}


