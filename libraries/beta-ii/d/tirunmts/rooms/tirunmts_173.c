// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_172.c",
"north": ROOMS"tirunmts_148.c",
"east": ROOMS"tirunmts_174.c",
"south": ROOMS"tirunmts_198.c",
  ]) );
}
