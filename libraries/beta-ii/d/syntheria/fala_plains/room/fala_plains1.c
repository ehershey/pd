
#include <std.h>
#include <fala_plains.h>

inherit VIRTUALROOM;

void create() {
     set_server(SERVER);
   ::create();
	
	set_exits(([
		"east": ROOMS"fala_plains2.c",
		"northeast": ROOMS"fala_plains125.c",
	]));

}
