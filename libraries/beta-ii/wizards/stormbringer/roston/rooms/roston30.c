#include <std.h>
#include <roston.h>

inherit ROOM;

void create() {
    ::create();
    set_name("north of town square");
    set_items((["snow"   : "A very deep white snow",
	"dirt"  : "A light brown mixture"]));
    set_properties((["light":2, "night light":2]));
    set_short("A dirt path");                      
    set_long("Your are at the base of a snow covered mountain. "
      "The mountain grows higher to the north,theres paths "
      "to the west and the east,they look as if there lead up "
      "other mountains and hills.");

    set_exits( ([ "north" : ROOMS "roston31",
	"west"  : "/d/coach/rooms/roston_coach.c",
	"south" : ROOMS "roston17"]));
    //            "west"  : ROOMS "roston40",
    //            "east"  : ROOMS "roston41"]));

}
