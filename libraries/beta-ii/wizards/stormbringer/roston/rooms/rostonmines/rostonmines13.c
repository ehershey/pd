/*  rostonmines
    Created by Stormy
*/

#include <std.h>
#include <rostonmines.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["west" : ROOMS "rostonmines12.c", "east" : ROOMS "rostonmines14.c"]));
}


