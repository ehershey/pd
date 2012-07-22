/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "tiruneastforest65.c", "north" : ROOMS "tiruneastforest58.c", "northwest" : ROOMS "tiruneastforest84.c"]));
}


