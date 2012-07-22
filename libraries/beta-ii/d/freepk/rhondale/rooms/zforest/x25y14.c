#include <std.h>
#include <daemons.h>
#include <aziraphale.h>

inherit VIRTUALROOM;

void create() {
    set_server(KEEPROOM"zforest/pathvserver.c");
    ::create();
    set_exits(([
	"northwest" : KEEPROOM"zforest/x24y13.c",
	"northeast" : KEEPROOM"zforest/x24y15.c",
      ]));
}
