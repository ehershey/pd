// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_306.c",
"northeast": ROOMS"tirunmts_301.c",
"south": ROOMS"tirunmts_312.c",
  ]) );
}
