// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"north": ROOMS"tirunmts_54.c",
"southeast": ROOMS"tirunmts_86.c",
"south": ROOMS"tirunmts_85.c",
  ]) );
}
