// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"southwest": ROOMS"tirunmts_162.c",
"down": ROOMS"tirunmts_163.c"
  ]) );
}
