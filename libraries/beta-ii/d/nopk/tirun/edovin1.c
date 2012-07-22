#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("East Dovin Road.");
    set_long(
      "Dovin Road is lightly traveled.  Houses line the road to the north. "
      "Built against the city wall, these houses are not much more than shacks.  "
      "The ancient stones underfoot running north and south make the road easy "
      "to follow. "
);
    set_night_long(
      "Running east and west through the northeast section of Tirun, "
      "Dovin Road is peaceful at night.  Shadows to the north show themselves "
      "to be buildings built against the city wall.  The stones underfoot are "
      "hard to make out in the darkness. "
);
    set_exits( 
              (["east" : ROOMS"edovin2",
                "west" : ROOMS"nveros6",
]) );
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into squares and layed to make a road.",
          "wall" : "A fortified wall that protects the city."
         ]) );
}
