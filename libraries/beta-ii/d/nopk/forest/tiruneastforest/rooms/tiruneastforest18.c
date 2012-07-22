/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest17.c", "northeast" : ROOMS "tiruneastforest19.c", "south" : ROOMS "tiruneastforest39.c"]));
}


