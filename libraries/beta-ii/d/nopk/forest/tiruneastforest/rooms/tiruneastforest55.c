/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["northwest" : ROOMS "tiruneastforest54.c", "east" : ROOMS "tiruneastforest56.c", "west" : ROOMS "tiruneastforest83.c"]));
}


