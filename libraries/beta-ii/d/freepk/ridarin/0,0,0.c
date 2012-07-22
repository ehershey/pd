
#include <std.h>
#include <ridarin.h>

inherit BEACH;

void create() {
  ::create();
  set_properties( ([ "no fly" : 1, "indoors" : 0, "light" : 1, "night light" : -1, "jungle" : 1 ]) );
  set_short("A very humid jungle");
  set_long("A small expanse of beach lies here with a steep sandy bank leading "
           "up towards the jungle. To the west is nothing but light green ocean, "
	   "to the east naught but vibrant green plants. A few stalwart trees "
	   "grow straight up out of the sand.");
  set_items( ([
    "beach" : "A small sandy bit of ground that barely separates the jungle from the ocean.",
    "jungle" : "The jungle is dense with trees, ferns, and other plants.",
    "ocean" : "Bright green, clean water sparkles invitingly.",
    "trees" : "A few of the jungle trees have managed to put down roots here.",
  ]) );
  set_smell("default", "A light scent of fresh rain and foliage fills the air.");
  set_inventory( ([ RIDARIN_ITEMS+"randomfood" : 1 ]) );
  set_exits( ([
    "east" : RIDARIN+"1,0,0",
  ]) );
  set_letter("o");
}

