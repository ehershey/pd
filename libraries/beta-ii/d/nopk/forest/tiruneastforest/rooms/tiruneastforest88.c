/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northwest" : ROOMS "tiruneastforest64.c", "east" : ROOMS "tiruneastforest89.c", "southwest" : ROOMS "tiruneastforest100.c"]));
}


