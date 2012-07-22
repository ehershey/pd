// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_71.c",
"northeast": ROOMS"tirunmts_55.c",
"south": ROOMS"tirunmts_93.c",
"southwest": ROOMS"tirunmts_92.c",
  ]) );
}
