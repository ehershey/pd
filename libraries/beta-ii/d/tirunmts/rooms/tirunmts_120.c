// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northwest": ROOMS"tirunmts_100.c",
"northeast": ROOMS"tirunmts_101.c",
"southwest": ROOMS"tirunmts_139.c",
"south": ROOMS"tirunmts_140.c"
  ]) );
}
