#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
 ::create();
    set_short("South Veros Road.");
    set_long(
      "Running north and south through the center of Tirun, Veros Road "
      "stays busy.  Mullin Road intersects Veros Road running east and "
      "west from here.  To the south the city gate opens onto the Tirun docks. "
      "The ancient stones underfoot run north, south, west, and east "
      "making the road easy to traverse. "
);
    set_night_long(
      "Running north and south through the center of Tirun, Veros Road "
      "is peaceful at night.  A dark road intersects Veros here leading "
      "west and east into the darkness.  Veros continues north and south. "
      " The Ancient stones underfoot are hard to make out in the dark. "
);
    set_exits( 
              (["north" : ROOMS"sveros5",
                "south" : ROOMS"sgate",
                "east"  : ROOMS "emullin1",
                "west"  : ROOMS "wmullin1",
]) );
    add_pre_exit_function("south", "go_south");
    set_property("light", 3);
    set_property("night light", 1);
    set_items(
        (["road" : "Ancient stones pave the ground.",
          "stones" : "Rocks carved into square and layed to make a road.",
          "marketplace" : "The center of commerce in Tirun.",
          "ships" : "Big boats berthed at the Tirun Docks.",
          "mast" : "A large pole on which a sail is hung."
         ]) );
}
int go_south() {
  if(!this_player()->is_player()) return 0;
  return 1;
}
void reset() {
    ::reset();
     if (children("/d/nopk/tirun/obj/mon/beggar.c")==({})||
         sizeof(children("/d/nopk/tirun/obj/mon/beggar.c"))==0)
            new(MOB "beggar")->move(this_object());
        
}
