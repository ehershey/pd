/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long("A couple of stingrays are sliding along the reef."
   " They are making quite a banquet of the crabs and crawfish in the area."
   " Some of the stingrays seem to be getting chased by two reef sharks."
  );

  set_exits(([
    "northeast":ROOMS2"room-2j3.c",
    "northwest":ROOMS2"room-2h3.c",
    "southwest":ROOMS2"room-2h5.c",
    "southeast":ROOMS2"room-2j5.c"
   ]));
  set_items(([
    "stingray":"There are several versions of stingray. This particular stingray is tan with blue dots scattered along its back.  They also have long whip-like tails made of cartilage with a toxic 'stinger' at the tip.",
    "crabs":"Crabs are the natural food of most stingrays.",
    "shark":"Most species of shark eat stingrays as a main source of food."
   ]));
  new(PEARLS"blue_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
