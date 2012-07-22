// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"west": ROOMS"tirunmts_217.c",
"northeast": ROOMS"tirunmts_192.c",
"southeast": ROOMS"tirunmts_236.c",
  ]) );
}