#include <std.h>
#include <helgrath.h>
inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("Yull Boulevard");
    set_long("Yull Boulevard is a highly traversed road leading north and south through "
      "the center of the town. To the north is the town square, and far to the south lie "
      "the Gates of Yalth. Pedestrians move about their tasks with a practiced "
      "indifference, paying no heed to the biting cold of the arctic winds."  );
    set_exits( ([ "north" : ROOMS "wilndursquare_mb",
      "south" : ROOMS "yullblvd_s02.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "The sounds of local gossip fill the air.");

}
