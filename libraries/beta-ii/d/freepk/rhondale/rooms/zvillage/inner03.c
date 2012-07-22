#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale East Road");
     set_day_long("The inner circle of Rhondale goes around the square and gives access to the various residencies of the town. Here the road intersects with the east and west path leading through the town square, to the west.");
     set_night_long("The inner circle of Rhondale goes around the square and gives access to the various residencies of the town. Here the road intersects with the east and west path leading through the town square, to the west. At night the road is void of people.");
     set_exits(([
                "east"          : KEEPROOM"zvillage/inouteast.c",
                "west"          : KEEPROOM"zvillage/insqeast.c",
                "north"         : KEEPROOM"zvillage/inner02.c",
                "south"         : KEEPROOM"zvillage/inner04.c",
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

