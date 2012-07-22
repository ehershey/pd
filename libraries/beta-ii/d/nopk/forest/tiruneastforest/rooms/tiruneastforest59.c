/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northeast" : ROOMS "tiruneastforest58.c", "west" : ROOMS "tiruneastforest60.c", "south" : ROOMS "tiruneastforest80.c"]));
}


