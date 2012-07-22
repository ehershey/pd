// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_211.c",
"east": ROOMS"tirunmts_213.c",
"southwest": ROOMS"tirunmts_234.c",
  ]) );
}
