/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest35.c", "east" : ROOMS "tiruneastforest37.c", "southeast" : ROOMS "tiruneastforest81.c"]));
}


