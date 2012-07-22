// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"north": ROOMS"tirunmts_275.c",
"northeast": ROOMS"tirunmts_276.c",
"south": ROOMS"tirunmts_293.c",
  ]) );
}
