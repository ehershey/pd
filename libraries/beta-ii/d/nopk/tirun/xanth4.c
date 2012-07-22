#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("Xanth Road.");
    set_long(
      "Xanth Road is lightly traveled.  Houses line the road to the "
      "east and west.  The ancient stones underfoot running east and "
      "west make the road easy to follow. "
);
    set_night_long(
      "Fallor Road is peaceful at night.  Shadows to the east and west "
      "show themselves to be buildings.  The stones underfoot are hard "
      "to make out in the darkness. "
);
    set_exits( 
              (["northwest" : ROOMS"seganthus1",
                "south" : ROOMS"xanth3",
                "east" : ROOMS"xanth5",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
void reset() {
    ::reset();
     if (children("/d/nopk/tirun/obj/mon/imp.c")==({})||
         sizeof(children("/d/nopk/tirun/obj/mon/imp.c"))==1)
            new(MOB "imp")->move(this_object());
        
}
