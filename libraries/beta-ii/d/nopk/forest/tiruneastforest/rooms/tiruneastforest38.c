/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northwest" : ROOMS "tiruneastforest37.c", "southeast" : ROOMS "tiruneastforest30.c", "northeast" : ROOMS "tiruneastforest53.c"]));
}


