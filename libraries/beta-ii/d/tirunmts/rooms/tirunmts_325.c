// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northeast": ROOMS"tirunmts_317.c",
"south": ROOMS"tirunmts_332.c",
  ]) );
}
