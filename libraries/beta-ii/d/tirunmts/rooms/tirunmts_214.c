// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"south": ROOMS"tirunmts_235.c",
"up": ROOMS"tirunmts_189.c"
  ]) );
}
