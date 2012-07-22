/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["east" : ROOMS "tiruneastforest12.c", "northwest" : ROOMS "tiruneastforest6.c", "southwest" : ROOMS "tiruneastforest20.c"]));
}


