#include <std.h>
#include <keep.h>
inherit VIRTUALROOM;
void create() {
    set_server(GARDEN_SERVER);
    ::create();
    set_exits(([
	"north":GARDEN+"36",
	"west":GARDEN+"47",
      ]));
}