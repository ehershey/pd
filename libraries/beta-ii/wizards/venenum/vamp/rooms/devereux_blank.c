#include <std.h>
#include <venenum.h>
inherit VAULT;

void create() {
    ::create();
    set_short("Store Room");
    set_long("This is but an empty store room, void of anything.");
    set_smell("default", "This smells of dust.");
    set_listen("default", "The house is quiet and peaceful.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"west" : ROOMS"devereux4.c",
      ]));
}

