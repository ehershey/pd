// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northeast": ROOMS"tirunmts_168.c",
"east": ROOMS"tirunmts_193.c",
"southwest": ROOMS"tirunmts_218.c",
  ]) );
}
