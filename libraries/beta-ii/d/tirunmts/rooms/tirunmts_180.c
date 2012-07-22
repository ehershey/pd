// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_179.c",
"north": ROOMS"tirunmts_151.c",
"southeast": ROOMS"tirunmts_203.c",
"south": ROOMS"tirunmts_202.c",
  ]) );
}
