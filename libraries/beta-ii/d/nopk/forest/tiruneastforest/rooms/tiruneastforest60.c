/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["east" : ROOMS "tiruneastforest59.c", "southwest" : ROOMS "tiruneastforest49.c"]));
}


