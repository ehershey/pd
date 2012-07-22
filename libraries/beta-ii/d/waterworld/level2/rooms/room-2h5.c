/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "Nautili are strongly present in this part of the reef."
   " They are feeding upon the crayfish and shrimp with their tentacles."
   " Some of the shrimp are being protected by hiding inside the anemones and between the tube worms on the reef."
  );

  set_exits(([
    "northeast":ROOMS2"room-2i4.c",
    "southeast":ROOMS2"room-2i6.c",
    "northwest":ROOMS2"room-2g4.c"
   ]));
  set_items(([
    "nautili":"These animals are a type of cephalopod."
    " They have a hard outer shell as opposed to the soft bodies of their cousins the squid and octopus."
    " They have tentacles and arms for feeding and a set of two specially evolved tentacles to close the shell when it needs protection.",
    "outer shell":"The nautilus shell is a series of chambers."
    " As a nautilus grows, it continually adds new chambers to the shell in an outwards spiral."
    " Each of the old chambers is sealed off with a divide called a septum."
    " There is a single tube called a siphuncle that connects all the chambers and permits the nautilus to control its buoyancy with osmotic pressure."
    " The last full chamber of the shell is where the nautilus lives."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
