#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "night light" : 1, "town" : 1]));
     set_name("Zartha City Market West");
     set_short("Zartha Market West");
     set_day_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\nHere the market leads out to the west side of town. Further to the south you can see a few shops, and the square is over east.\n");
     set_night_long("%^BOLD%^BLACK%^Zartha Marketplace\nThe market here leads out to west Zartha, though the road is just a huge shadow. A few points of light to teh south indicate shops, and brighter light to the east is the square.");
     set_items(([

                ]));
     set_exits(([
                "west"		: KEEPROOM"wpaper1.c",
                "north"		: KEEPROOM"[]northwest.c",
                "east"		: KEEPROOM"[].c",
                "south"		: KEEPROOM"[]southwest.c"
                ]));
}
