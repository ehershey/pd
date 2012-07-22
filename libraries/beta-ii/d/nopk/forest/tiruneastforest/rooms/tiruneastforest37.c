/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "tiruneastforest36.c", "southeast" : ROOMS "tiruneastforest38.c", "northeast" : ROOMS "tiruneastforest101.c"]));
}


