#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Gate of the Moon");
    set_long("Massive trunks of gray, twisted oak line the sides of the long forest path of rich, dark soil. "
      "A canopy of thick, knotted branches forms an impenetrable ceiling overhead. Huge, knotted "
      "roots intertwine in precarious formations along the path, threatening serious "
      "hazard to any unwary traveler. ");
    set_exits( ([ "gate" : ROOMS "marketrd_egate.c",
      "east" : ROOMS "forest_w02.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint croaking noise can be heard.");

}
