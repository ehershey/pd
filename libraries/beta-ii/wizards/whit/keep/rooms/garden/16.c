#include <std.h>
#include <keep.h>
inherit VIRTUALROOM;
void create() {
    set_server(GARDEN_SERVER);
    ::create();
    set_exits(([
	"east":GARDEN+"17",
	"northwest":GARDEN+"3"
      ]));
}
