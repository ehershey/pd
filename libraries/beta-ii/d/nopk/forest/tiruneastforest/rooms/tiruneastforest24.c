/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["north" : ROOMS "tiruneastforest12.c", "southeast" : ROOMS "tiruneastforest25.c", "southwest" : ROOMS "tiruneastforest73.c"]));
}


