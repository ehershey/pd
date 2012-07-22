/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
//  set_listen("bubbles","You have followed the sound of the bubbles and located a fissure in the reef's surface.  Perhaps there is a lower level to explore?");
  set_smell("default","There are some foul smelling bubbles float up to the surface.");
//  set_smell("bubbles","The bubbles smell like methane. Listening to them may let you learn where they are originating from.");
  set_long(
   " A collection of short-finned eels are laying their eggs on the surface of the water above the reef in this area."
   " Some of them are attacking the small birds and baitfish."
   " The outgoing tide is carrying most of the eggs out into the ocean."
   " It would appear that the reef and its residents are too deep in the ocean for the eels to attack them."
  );
//  add_invis_exit("fissure");
  set_exits(([
//    "fissure":ROOMS3"room-3b9.c",
    "west":ROOMS2"room-2e6.c"
   ]));
  set_items(([
//    "fissure":"It appears to be an exit hidden in the reef's surface.",
    "eels":"The eels, members of the family Anguillidae, have long tubular bodies similar to snakes."
    " Unlike fish, an eel's dorsal and posterior fins are of equal size."
    " An eel's lifespan is an average of 19 years."

    "\n\nThey are catadromous animals, meaning they start their lives in saltwater and migrate inland to freshwater locations as adults."
    " They have several adaptations that permit this type of migration pattern:"
    " They have the ability to absorb oxygen through their skin,"
    " they can endure long periods without food,"
    " and they can even endure long periods of low temperatures by entering into a state of hybernation called a torpor which means a slowed down metabolism but not to the point of sleep."
    ,
    "eggs":"The eel eggs can drift upon the open oceans for several months before hatching into elvers."
    " The elvers then migrate into freshwater.",
    "reef":"Like every other part of the reef, it is covered in sea anemones, crustaceans, sea grass, and other organisms."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
