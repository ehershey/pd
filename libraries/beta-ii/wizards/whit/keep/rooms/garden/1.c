#include <std.h>
#include <keep.h>
inherit VIRTUALROOM;
void create() {
    set_server(GARDEN_SERVER);
    ::create();
    set_exits(([
	"south":GARDEN+"14",
	"east":GARDEN+"2",
      ]));
}
