/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest93.c", "east" : ROOMS "tiruneastforest95.c"]));
}


