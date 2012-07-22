/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northwest" : ROOMS "tiruneastforest85.c", "south" : ROOMS "tiruneastforest87.c", "northeast" : ROOMS "tiruneastforest105.c"]));
}


