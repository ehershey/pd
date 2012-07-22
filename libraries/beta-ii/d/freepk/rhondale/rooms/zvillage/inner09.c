#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale East Road");
     set_day_long("The inner circle of Rhondale goes around the square and gives access to the various residencies of the town. Here the road intersects with the east and west path leading through the town square, to the east.");
     set_night_long("The inner circle of Rhondale goes around the square and gives access to the various residencies of the town. Here the road intersects with the east and west path leading through the town square, to the east. At night the road is void of people.");
     set_exits(([
                "east"          : KEEPROOM"zvillage/insqwest.c",
                "west"          : KEEPROOM"zvillage/inoutwest.c",
                "north"         : KEEPROOM"zvillage/inner10.c",
                "south"         : KEEPROOM"zvillage/inner08.c",
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

