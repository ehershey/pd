#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "town" : 1]));
     set_name("Zartha City Square");
     set_short("Zartha Square");
     set_day_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\nThe eastern sector of Zartha market leads onto a main road that goes past the inn. Further to the south are a few shops, and the square lies to the west.");
     set_night_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\n%^BOLD%^BLACK%^The marketplace at night is filled with shadows, the darkness consuming everything. Shops to the south can barely be made out, as well as a road to the east.");
     set_exits(([
                "north"         : KEEPROOM"[]northeast.c",
                "south"         : KEEPROOM"[]southeast.c",
                "east"          : KEEPROOM"epaper1.c",
                "west"          : KEEPROOM"[].c"
                ]));
}
