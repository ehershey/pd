// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_171.c",
"east": ROOMS"tirunmts_173.c",
"southwest": ROOMS"tirunmts_197.c",
  ]) );
}
