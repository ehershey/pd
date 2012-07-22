// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_238.c",
"north": ROOMS"tirunmts_219.c",
"east": ROOMS"tirunmts_240.c",
  ]) );
}
