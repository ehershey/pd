/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northwest" : ROOMS "tiruneastforest26.c", "east" : ROOMS "tiruneastforest47.c"]));
}


