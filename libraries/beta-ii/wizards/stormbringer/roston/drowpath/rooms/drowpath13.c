/*  drowpath
    Created by Stormy
*/

#include <std.h>
#include <drowpath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "drowpath2.c", "north" : ROOMS "drowpath14.c", "northwest" : ROOMS "drowpath4.c"]));
}


