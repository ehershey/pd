// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northeast": ROOMS"tirunmts_122.c",
"southeast": ROOMS"tirunmts_164.c",
"southwest": ROOMS"tirunmts_163.c",
"up": ROOMS"tirunmts_121.c"
  ]) );
}
