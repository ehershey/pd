/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest3.c", "east" : ROOMS "tiruneastforest5.c", "south" : ROOMS "tiruneastforest76.c"]));
}


