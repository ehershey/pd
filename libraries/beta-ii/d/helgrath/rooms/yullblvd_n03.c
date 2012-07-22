#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
    ]));
    set_short("Yull Boulevard");
    set_long("This area of Yull Boulevard appears very busy, as citizens scurry about on their "
      "way to or from various tasks. To the north in the distance, the Temple towers above the city, "
      "reaching for the heavens." );
    set_exits( ([ "north" : ROOMS "yullblvd_n04.c",
      "south" : ROOMS "yullblvd_n02.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}
