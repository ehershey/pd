// Coded by Whit

#include <std.h>

#include <citrin.h>
inherit ROOM;

void create() {
::create();
set_name("A snake's nest");
set_long("This is a very ugly snake nest.  "
"Many snakes live here.  <FILL MORE> ");
set_exits(([
"north" : ROOMS"openpath_6.c",
]));
}

