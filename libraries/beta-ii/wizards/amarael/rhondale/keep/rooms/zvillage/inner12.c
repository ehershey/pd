#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale East Road");
     set_day_long("The inner circle of Rhondale goes around the square and gives access to the various residencies of the town. Here the road intersects with the north and south path leading through the town square, to the south.");
     set_night_long("The inner circle of Rhondale goes around the square and gives access to the various residencies of the town. Here the road intersects with the north and south path leading through the town square, to the south. At night the road is void of people.");
     set_exits(([
                "south"         : KEEPROOM"zvillage/insqnorth.c",
                "north"         : KEEPROOM"zvillage/inoutnorth.c",
                "east"          : KEEPROOM"zvillage/inner01.c",
                "west"          : KEEPROOM"zvillage/inner11.c",
                ]));
}
void reset() {
   ::reset();
     if (!present("monster")) {
        new(KEEPMOB"zvillage/townguard.c")->move(this_object());
        new(KEEPMOB"zvillage/townguard.c")->move(this_object());
        new(KEEPMOB"zvillage/townguard.c")->move(this_object());
	}
}
