/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest9.c", "southeast" : ROOMS "tiruneastforest32.c"]));
}


