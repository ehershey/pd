#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Yull Boulevard");
    set_long("Yull Boulevard is the main road leading north and south through the center "
      "of town.  Temple slaves work here, busily shoveling snow from the streets to clear a "
      "path for the citizens. ");
    set_exits( ([ "north" : ROOMS "yullblvd_s02.c",
      "south" : ROOMS "yullblvd_s04.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sound of conversation drifts in from the north.");

}
