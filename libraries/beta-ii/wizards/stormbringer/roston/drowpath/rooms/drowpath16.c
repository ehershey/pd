/*  drowpath
    Created by Stormy
*/

#include <std.h>
#include <drowpath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "drowpath15.c", "northwest" : ROOMS "drowpath7.c", "northeast" : ROOMS "drowpath25.c"]));
}


