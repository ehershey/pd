/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["east" : ROOMS "tiruneastforest71.c", "west" : ROOMS "tiruneastforest54.c"]));
}


