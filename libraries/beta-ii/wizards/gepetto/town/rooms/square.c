//Gepetto


#include <std.h>
#include <gepetto.h>

inherit ROOM;

void create() {
::create();
set_property ("plain", 1);
set_property ("outdoors" ,1);
set_property ("light", 3);
set_property ("night light", 2);
set_property ("no attack", 1);
set_property ("no magic", 1);
set_property ("no steal", 1);

set_short ("Rawlthford Square");
set_long ("Welcome to the city of Rawlthford. Adventurers from "
      "far and near come here to trade,barter, or simply "
     "look for things to do. An opaque bubble can be seen floating "
     "over the well kept streets. The various residents of this "
     "town pay it little mind as they bustle about their daily "
     "activities. ");
set_items(([
  "square" : "This square is the center of rawthford.",
  "streets" : "The well kept,clean streets stretch out in the four cardinal directions.",
  "residents" : "Residents of every class and race bustle about their daily activities.",
  "bubble" : "The opaque bubble floats over the city. One can only assume that it houses Gepettos workshop.",
]));
set_exits(([
     "north" : ROOMS "power10.c",
     "south" : ROOMS "power8.c",
]));

}
