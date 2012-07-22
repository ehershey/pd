/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest47.c", "northeast" : ROOMS "tiruneastforest49.c", "southeast" : ROOMS "tiruneastforest62.c"]));
}


