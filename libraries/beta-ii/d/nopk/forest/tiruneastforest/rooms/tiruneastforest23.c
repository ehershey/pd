/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest22.c", "southeast" : ROOMS "tiruneastforest8.c", "northeast" : ROOMS "tiruneastforest44.c"]));
}


