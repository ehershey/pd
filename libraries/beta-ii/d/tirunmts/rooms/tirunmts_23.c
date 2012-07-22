// Made by Stormy 6/26/2004

#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"north": ROOMS"tirunmts_13.c",
"northeast": ROOMS"tirunmts_14.c",
"southeast": ROOMS"tirunmts_30.c",
  ]) );
}
