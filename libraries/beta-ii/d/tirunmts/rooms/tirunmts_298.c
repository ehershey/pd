// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"north": ROOMS"tirunmts_295.c",
"east": ROOMS"tirunmts_299.c",
"southwest": ROOMS"tirunmts_302.c",
  ]) );
}
