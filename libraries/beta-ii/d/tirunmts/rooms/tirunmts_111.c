// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"north": ROOMS"tirunmts_88.c",
"northeast": ROOMS"tirunmts_89.c",
"southeast": ROOMS"tirunmts_131.c",
  ]) );
}