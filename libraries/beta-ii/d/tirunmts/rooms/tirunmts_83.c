// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_82.c",
"northeast": ROOMS"tirunmts_65.c",
"east": ROOMS"tirunmts_84.c",
"south": ROOMS"tirunmts_102.c",
  ]) );
}
