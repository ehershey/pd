#include <std.h>
#include <keep.h>
inherit VIRTUALROOM;
void create() {
    set_server(GARDEN_SERVER);
    ::create();
    set_exits(([
	"southwest":GARDEN+"37",
	"east":GARDEN+"26",
      ]));
}
