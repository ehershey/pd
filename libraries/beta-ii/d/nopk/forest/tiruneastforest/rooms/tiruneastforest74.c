/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northeast" : ROOMS "tiruneastforest73.c", "west" : ROOMS "tiruneastforest75.c"]));
}


