#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
 ::create();
    set_short("North Haven Road.");
    set_long(
      "Haven Road is lightly traveled.  Houses line the road to the north and west. "
      "Built against the city wall, these houses are not much more than shacks.  "
      "The ancient stones underfoot running east and south make the road easy "
      "to follow. "
);
    set_night_long(
      "Running north and south through the northwest section of Tirun, "
      "Dovin Road is peaceful at night.  Shadows to the north and west show themselves "
      "to be buildings built against the city wall.  The stones underfoot are "
      "hard to make out in the darkness. "
);
    set_exits( 
              (["east" : ROOMS"wdovin6",
                "south" : ROOMS"nhaven6",
                "enter west warehouse" : ROOMS"warehouse2",
                "enter north warehouse" : ROOMS"warehouse",
]) );
add_exit_alias("enter west warehouse", "west warehouse");
add_exit_alias("enter west warehouse", "west");
add_exit_alias("enter west warehouse", "w");
add_exit_alias("enter north warehouse", "north warehouse");
add_exit_alias("enter north warehouse", "north");
add_exit_alias("enter north warehouse", "n");
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
     if (children("/d/nopk/tirun/obj/mon/chance.c")==({})||
         sizeof(children("/d/nopk/tirun/obj/mon/chance.c"))==1)
            new(MOB "chance")->move(this_object());
	
}
