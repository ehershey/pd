// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"north": ROOMS"tirunmts_294.c",
"down": ROOMS"tirunmts_301.c"
  ]) );
}
