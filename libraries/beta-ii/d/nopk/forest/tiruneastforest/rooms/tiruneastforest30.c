/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "tiruneastforest29.c", "west" : ROOMS "tiruneastforest34.c", "northwest" : ROOMS "tiruneastforest38.c", "southeast" : ROOMS "tiruneastforest51.c", "northeast" : ROOMS "tiruneastforest83.c"]));
}


