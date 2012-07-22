// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northwest": ROOMS"tirunmts_299.c",
"north": ROOMS"tirunmts_300.c",
"southwest": ROOMS"tirunmts_310.c",
  ]) );
}
