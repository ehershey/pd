#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 2, "town" : 1]));
     set_short("Rhondale East Road");
     set_day_long("The inner circle of Rhondale goes around the square and gives access to the various residencies of the town. Here the road intersects with the north and south path leading through the town square, which is to the north.");
     set_night_long("The inner circle of Rhondale goes around the square and gives access to the various residencies of the town. Here the road intersects with the north and south path leading through the town square, which is to the north. At night the road is void of people.");
     set_exits(([
                "south"         : KEEPROOM"zvillage/inoutsouth.c",
                "north"         : KEEPROOM"zvillage/insqsouth.c",
                "east"          : KEEPROOM"zvillage/inner05.c",
                "west"          : KEEPROOM"zvillage/inner07.c",
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
