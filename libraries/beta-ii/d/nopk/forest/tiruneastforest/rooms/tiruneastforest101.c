/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southeast" : ROOMS "tiruneastforest53.c", "southwest" : ROOMS "tiruneastforest37.c"]));
}


