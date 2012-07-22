/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["east" : ROOMS "tiruneastforest1.c", "northwest" : "/d/nopk/standard/outland1.c"]));
}


