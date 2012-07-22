// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northwest": ROOMS"tirunmts_74.c",
"northeast": ROOMS"tirunmts_75.c",
"south": ROOMS"tirunmts_117.c",
  ]) );
}
