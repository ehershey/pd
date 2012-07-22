/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest67.c", "northwest" : ROOMS "tiruneastforest69.c", "north" : ROOMS "tiruneastforest87.c", "south" : ROOMS "tiruneastforest92.c"]));
}


