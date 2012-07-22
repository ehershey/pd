/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest51.c", "northeast" : ROOMS "tiruneastforest56.c", "southeast" : ROOMS "tiruneastforest84.c"]));
}


