//Aziraphale

#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 2, "night light" : 1, "town" : 1]));
     set_name("Zartha City Market South");
     set_short("Zartha Market South");
     set_day_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\nThe south of the marketplace connects to the main road, leading out of the city. The park is further to the north, and various shops are spread out to the east and west.");
     set_night_long("%^BOLD%^BLACK%^Zartha Marketplace%^RESET%^\n%^BOLD%^BLACK%^The marketplace becomes a haven for darkness during the night, the shadows shifting constantly. The stones underfoot are wet and slippery. The safety of the square lies north, and there are a few shops further off to teh east and west.");
     set_items(([

		]));
     set_exits(([
		"north"		: KEEPROOM"[].c",
                "south"         : KEEPROOM"port1.c",
		"east"		: KEEPROOM"[]southeast.c",
		"west"		: KEEPROOM"[]southwest.c"
		]));
}
