/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest46.c", "northeast" : ROOMS "tiruneastforest48.c", "southeast" : ROOMS "tiruneastforest97.c"]));
}


