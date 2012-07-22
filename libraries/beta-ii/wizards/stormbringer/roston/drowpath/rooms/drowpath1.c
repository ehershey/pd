/*  drowpath
    Created by Stormy
*/

#include <std.h>
#include <drowpath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "drowpath0.c", "north" : ROOMS "drowpath2.c"]));
}


