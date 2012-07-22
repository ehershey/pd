/*  drowpath
    Created by Stormy
*/

#include <std.h>
#include <drowpath.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
    set_exits((["southwest" : ROOMS "drowpath10.c", "northwest" : ROOMS "drowpath12.c", "southeast" : ROOMS "drowpath22.c"]));
}


