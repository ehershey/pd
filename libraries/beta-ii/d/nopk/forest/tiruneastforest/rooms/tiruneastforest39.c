/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["north" : ROOMS "tiruneastforest18.c", "southeast" : ROOMS "tiruneastforest40.c"]));
}


