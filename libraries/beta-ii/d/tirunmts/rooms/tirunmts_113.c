// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_112.c",
"northeast": ROOMS"tirunmts_91.c",
"southeast": ROOMS"tirunmts_132.c",
  ]) );
}
