/*  drowpath
    Created by Stormy
*/

#include <std.h>
#include <drowpath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "drowpath13.c", "north" : ROOMS "drowpath15.c"]));
}


