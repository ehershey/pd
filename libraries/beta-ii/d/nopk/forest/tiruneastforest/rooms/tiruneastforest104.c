/*  tiruneastforest
    Created by Stormy
*/

#include <std.h>
#include <tiruneastforest.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();


    set_exits((["southwest" : ROOMS "tiruneastforest103.c", "northwest" : ROOMS "tiruneastforest105.c", "northeast" : "/d/forest/nwvforest1/wrooms/room1.c"]));
}
