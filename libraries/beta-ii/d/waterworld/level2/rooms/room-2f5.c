/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_listen("default","You hear the playful barks of a harbor seal.");
  set_long(
   "This area of the reef is being visited by a family of harbor seals."
   " The seals seem to be attracted to the reef by the abundant food supply here."
   " Almost all species of fish and crawfish are part of a seal's diet."
   " Fortunately for some of the fish, they have secured hiding spots among the tubeworms and sea anemones that line the reef."
  );

  set_exits(([
    "northeast":ROOMS2"room-2g4.c",
    "northwest":ROOMS2"room-2e4.c",
    "southwest":ROOMS2"room-2e6.c"
   ]));
  set_items(([
    "seal":"Most of the seals are silver gray to almost black in color."
    " They have large well developed eyes and webbed feet."
    " Their bodies have many layers of blubber to insulate from the enviroment and shield their organs from attack."
    "\n\nThe seals have several adaptations that allow them to dive deep into the ocean for their prey."
    " They can adjust their heart and metabolic rates and lower their body temperatures; "
    "the most useful adaptation however is the fact that they can stockpile oxygen in their muscle tissues."
    " In addition to storing oxygen for the dive, they can also withstand large amounts of carbon dioxide (carbon dioxide poisoning is commonly refered to by divers as 'the bends'). This allows them to dive to great depths and surface without any ill affects.",
    "fish":"The fish are the primary food source of the seals. Some are being shielded by the other organisms and structures on the reef."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
