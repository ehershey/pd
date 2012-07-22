#include <std.h>
#include <tirun.h>
inherit ROOM;

void create() {
    ::create();
    set_short("South Veros Road.");
    set_long(
      "Running north and south through the center of Tirun, "
      "Veros Road stays busy.  The road to the north opens into "
      "a broad marketplace that marks the center of Tirun.  Far "
      "to the south, the masts of ships can be seen above the "
      "city walls.  Ancient stones underfoot run north and "
      "south making the road easy to traverse."
    );
    set_night_long(
      "Running north and south through the center of Tirun, " 
      "Veros Road is peaceful at night.  The shadows to the "
      "north suggest a place of many buildings, while to the "
      "south the road leads away into darkness.  The stones "
      "underfoot are hard to make out in the dark."
    );
    set_exits( 
      (["north" : ROOMS"square5",
	"south" : ROOMS"sveros2",
      ]) );

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
