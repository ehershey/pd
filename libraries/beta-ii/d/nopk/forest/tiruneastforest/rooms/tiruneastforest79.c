/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "tiruneastforest63.c", "northeast" : ROOMS "tiruneastforest80.c"]));
}

