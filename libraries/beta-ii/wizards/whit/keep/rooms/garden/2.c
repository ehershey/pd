#include <std.h>
#include <keep.h>
inherit VIRTUALROOM;
void create() {
    set_server(GARDEN_SERVER);
    ::create();
    set_exits(([
	"west":GARDEN+"1",
	"east":GARDEN+"3",
      ]));
}
