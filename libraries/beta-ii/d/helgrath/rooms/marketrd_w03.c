#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Market Road");
    set_long("The road widens here, allowing room to pass as various merchants peddle "
      "their goods under the awnings of the towering buildings to either side of the road. " );
    set_exits( ([ "west" : ROOMS "marketrd_w04.c",
      "east" : ROOMS "marketrd_w02.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "Numerous merchants call out pedestrians as they pass, begging them to buy their goods.");

}
