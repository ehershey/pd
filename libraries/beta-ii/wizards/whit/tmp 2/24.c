#include <std.h>
#include <event.h>

inherit VIRTUALROOM;
void create() {
    set_server(SERVER);
    ::create();
    set_exits(([
	"north":ROOMS"22",
	"south":ROOMS"26",
      ]));
}

