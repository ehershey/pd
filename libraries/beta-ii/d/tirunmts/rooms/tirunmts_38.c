// Made by Stormy 6/26/2004
#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"northwest": ROOMS"tirunmts_33.c",
"east": ROOMS"tirunmts_39.c",
"south": ROOMS"tirunmts_43.c",
  ]) );
}
