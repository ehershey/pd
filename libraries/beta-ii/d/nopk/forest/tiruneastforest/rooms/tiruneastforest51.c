/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "tiruneastforest50.c", "northwest" : ROOMS "tiruneastforest30.c", "northeast" : ROOMS "tiruneastforest61.c"]));
}


