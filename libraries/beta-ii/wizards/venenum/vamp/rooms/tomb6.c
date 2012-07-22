#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Darkness.");
    set_long("You are in pure blackness, presumably inside the stone and earth beneath the mausoleum. There is nothing to do or see here.");
    set_smell("default", "There are no smells here.");
    set_listen("default", "There are no sounds here.");

    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"down" : ROOMS"tomb7.c",
	"up" : ROOMS"tomb5.c",
      ]));
}
