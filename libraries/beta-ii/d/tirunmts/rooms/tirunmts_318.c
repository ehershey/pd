// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_317.c",
"northeast": ROOMS"tirunmts_311.c",
"southeast": ROOMS"tirunmts_326.c",
  ]) );
}
