/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northeast" : ROOMS "tiruneastforest11.c", "west" : ROOMS "tiruneastforest13.c", "south" : ROOMS "tiruneastforest24.c"]));
}


