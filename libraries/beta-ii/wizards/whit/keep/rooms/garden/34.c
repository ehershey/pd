#include <std.h>
#include <keep.h>
inherit VIRTUALROOM;
void create() {
    set_server(GARDEN_SERVER);
    ::create();
    set_exits(([
	"west":GARDEN+"33",
	"east":GARDEN+"35",
      ]));
}
