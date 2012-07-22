// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_57.c",
"northeast": ROOMS"tirunmts_48.c",
"southeast": ROOMS"tirunmts_73.c",
  ]) );
}
