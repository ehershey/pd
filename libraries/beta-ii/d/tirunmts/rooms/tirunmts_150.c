// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northwest": ROOMS"tirunmts_132.c",
"north": ROOMS"tirunmts_133.c",
"southeast": ROOMS"tirunmts_178.c",
"southwest": ROOMS"tirunmts_177.c",
  ]) );
}
