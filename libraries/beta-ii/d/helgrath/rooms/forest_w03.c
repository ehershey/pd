#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Dark Woods");
    set_long("Massive trunks of gray, twisted oak line the sides of the long forest path. Several "
      "varying types of animal tracks can be made out in the dark soil underfoot. Large, ragged "
      "looking weeds reach up to ensnare uncautious passerby. ");
    set_exits( ([ "west" : ROOMS "forest_w02.c",
      "east" : ROOMS "forest_pier.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint croaking noise can be heard.");

}
