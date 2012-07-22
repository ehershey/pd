// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"southeast": ROOMS"tirunmts_308.c",
"southwest": ROOMS"tirunmts_307.c",
"up": ROOMS"tirunmts_297.c"
  ]) );
}
