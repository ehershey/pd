#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("South Haven Road.");
    set_long(
      "Haven Road is lightly traveled.  Houses line the road to the west. "
      "Built against the city wall, these houses are not much more than shacks.  "
      "The ancient stones underfoot running north and southeast make the road easy "
      "to follow. "
);
    set_night_long(
      "Running north and south through the southwest section of Tirun, "
      "Dovin Road is peaceful at night.  Shadows to the west show themselves "
      "to be buildings built against the city wall.  The stones underfoot are "
      "hard to make out in the darkness. "
);
    set_exits( 
              (["north" : ROOMS"shaven5",
                "southeast" : ROOMS"wmullin6",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
