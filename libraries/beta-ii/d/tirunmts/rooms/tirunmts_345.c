// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"east": ROOMS"tirunmts_346.c",
"southwest": ROOMS"tirunmts_348.c",
  ]) );
}
