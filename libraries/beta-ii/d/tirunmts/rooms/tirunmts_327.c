// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_326.c",
"northeast": ROOMS"tirunmts_319.c",
"east": ROOMS"tirunmts_328.c",
"southeast": ROOMS"tirunmts_333.c",
  ]) );
}
