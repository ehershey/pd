// Made by Stormy 6/26/2004

#include <std.h>
#include <tirunmts.h>

inherit VIRTUALROOM;

void create() {
  set_server(SERVER);
  ::create();
  set_exits( ([ 

"east": "/d/durst/room/muabark001.c",
"northwest": ROOMS"tirunmts_1.c",
"south": ROOMS"tirunmts_6.c",
  ]) );
}
