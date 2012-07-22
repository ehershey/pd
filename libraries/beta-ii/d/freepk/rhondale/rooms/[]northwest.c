#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "night light" : 1, "town" : 1]));
     set_name("Zartha City Market Northwest");
     set_short("Zartha Market Northwest");
     set_day_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\nThe northeast part of the marketplace is bare, with all the shops being further to the south. A guard post of the castle is just to the north, and the square lies to the southeast.");
     set_night_long("%^BOLD%^BLACK%^Zartha Marketplace\nAt night the market crawls with shadows. The stones underfoot are mouldy and hard to keep balance on. The square lies just to the southeast, and a castle guard post looms out from the dark.");
     set_items(([

                ]));
     set_exits(([
                "south"         : KEEPROOM"[]west.c",
                "east"          : KEEPROOM"[]north.c"
                ]));
}
