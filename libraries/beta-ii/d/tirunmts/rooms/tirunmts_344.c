// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_343.c",
"northeast": ROOMS"tirunmts_338.c",
"southeast": ROOMS"tirunmts_347.c",
  ]) );
}
