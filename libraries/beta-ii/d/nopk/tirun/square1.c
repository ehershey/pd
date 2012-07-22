#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_property("light", 2);
    set_property("night light", 1);
    set_short("Tirun Market Square.\n");
//DO NOT CHANGE THIS DESCRIPTION!!!!
    set_long(
      "%^BOLD%^%^WHITE%^Tirun Market Square.%^RESET%^\n"
      "The market is bustling with activity.  Buildings to the east "
      "stand along the side of the road and one large building to the "
      "west dominates the northwest corner of the market. "
      " Ancient stone tiles underfoot run north, west, and east making "
      "the road easy to follow.  A fence to the south marks the boundaries "
      "of a park and an opening in the fence provides access there in. "
      " Veros road leads the way north toward the city walls of Tirun. "
    );
//DO NOT CHANGE THE NIGHT DESCRIPTION!!!!
    set_night_long(
      "%^BOLD%^%^WHITE%^Tirun Market Square.%^RESET%^\n"
      "The square is dark and quiet.  Dark forms moving in the darkness lend "
      "evidence that at least some creatures roam the night.  Shadows along "
     "the side of the road to the east and west coalesce into buildings.  "
      "The stones underfoot are hard to make out and things look different "
      "in the darkness.  The road seems to travel north, west, and east.  "
      "An opening in the fence to the south leads into a well lit area. "
      );
    set_exits( ([
        "north" : ROOMS "nveros1",
        "south" : ROOMS "square",
        "west" : ROOMS "square8",
        "east" : ROOMS "square2" 
      ]) );

    set_items( ([
        "road" : "Ancient stone tiles pave the road.",
        "shop" : "A place to buy and trade goods.",
        "shops" : "Places to buy and trade goods.",
        "fence" : "A wooden structure.",
        "building" : "A structure made of stone.",
        "square" : "The Market Square of Tirun.",
        "sign" : "A shingle with a painting on it."
    ]) );
}
void reset() {
    ::reset();
     if (children("/d/nopk/tirun/obj/mon/rejik.c")==({})||
         sizeof(children("/d/nopk/tirun/obj/mon/rejik.c"))==0)
            new(MOB "rejik")->move(this_object());
        
}
