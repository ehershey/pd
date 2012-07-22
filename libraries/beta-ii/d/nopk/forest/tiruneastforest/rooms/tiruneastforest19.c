/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest18.c", "east" : ROOMS "tiruneastforest20.c", "northwest" : ROOMS "tiruneastforest76.c"]));
}


