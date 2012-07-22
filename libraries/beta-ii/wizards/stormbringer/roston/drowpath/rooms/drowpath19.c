/*  drowpath
    Created by Stormy
*/

#include <std.h>
#include <drowpath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["south" : ROOMS "drowpath18.c", "north" : ROOMS "drowpath20.c"]));
}


