/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest38.c", "east" : ROOMS "tiruneastforest54.c", "northwest" : ROOMS "tiruneastforest101.c"]));
}


