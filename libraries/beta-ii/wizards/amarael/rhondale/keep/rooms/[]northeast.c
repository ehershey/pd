#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "town" : 1,]));
     set_name("Zartha Market Northeast");
     set_short("Zartha Market Northeast");
     set_day_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\nThe marketplace nowadays is an empty place, especially here with the castle guard posts just to the north over the river. Nothing else is here but the western wall of the inn.");
     set_night_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\n%^BOLD%^BLACK%^The night brings an unnatural darkness to the area, shadows cover everything. To the north you can just make out a castle guard post, and to the east a wall of the inn.");
     set_exits(([
                "south"         : KEEPROOM"[]east.c",
                "west"          : KEEPROOM"[]north.c"
                ]));
}
