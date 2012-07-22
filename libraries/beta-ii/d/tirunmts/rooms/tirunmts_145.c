// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_144.c",
"northwest": ROOMS"tirunmts_125.c",
"southeast": ROOMS"tirunmts_167.c",
  ]) );
}
