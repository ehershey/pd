/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["north" : ROOMS "tiruneastforest33.c", "southwest" : ROOMS "tiruneastforest52.c"]));
}


