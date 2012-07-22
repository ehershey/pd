// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northwest": ROOMS"tirunmts_150.c",
"east": ROOMS"tirunmts_179.c",
"southwest": ROOMS"tirunmts_201.c",
  ]) );
}
