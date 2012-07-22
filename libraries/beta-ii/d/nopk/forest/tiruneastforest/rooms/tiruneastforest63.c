/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest62.c", "northeast" : ROOMS "tiruneastforest64.c", "north" : ROOMS "tiruneastforest79.c"]));
}


