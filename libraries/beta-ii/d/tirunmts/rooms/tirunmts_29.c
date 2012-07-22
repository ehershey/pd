// Made by Stormy 6/26/2004

#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northwest": ROOMS"tirunmts_20.c",
"northeast": ROOMS"tirunmts_21.c",
"southeast": ROOMS"tirunmts_36.c",
  ]) );
}
