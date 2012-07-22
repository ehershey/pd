// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_127.c",
"northeast": ROOMS"tirunmts_109.c",
"southeast": ROOMS"tirunmts_146.c",
  ]) );
}
