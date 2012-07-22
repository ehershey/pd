// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northeast": ROOMS"tirunmts_252.c",
"east": ROOMS"tirunmts_264.c",
"southeast": ROOMS"tirunmts_274.c",
  ]) );
}
