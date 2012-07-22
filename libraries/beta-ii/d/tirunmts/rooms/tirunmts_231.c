// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"north": ROOMS"tirunmts_210.c",
"east": ROOMS"tirunmts_232.c",
"southwest": ROOMS"tirunmts_251.c",
  ]) );
}
