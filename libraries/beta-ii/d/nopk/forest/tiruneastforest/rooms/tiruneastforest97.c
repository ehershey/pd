/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest96.c", "east" : ROOMS "tiruneastforest98.c", "northwest" : ROOMS "tiruneastforest47.c", "northeast" : ROOMS "tiruneastforest62.c"]));
}


