#include <std.h>
#include <keep.h>
inherit VIRTUALROOM;
void create() {
    set_server(GARDEN_SERVER);
    ::create();
    set_exits(([
	"southeast":GARDEN+"51",
	"west":GARDEN+"39",
      ]));
}
