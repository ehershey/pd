// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_278.c",
"northeast": ROOMS"tirunmts_270.c",
"east": ROOMS"tirunmts_280.c",
  ]) );
}
