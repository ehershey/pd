/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest5.c", "north" : ROOMS "tiruneastforest7.c", "southeast" : ROOMS "tiruneastforest13.c"]));
}


