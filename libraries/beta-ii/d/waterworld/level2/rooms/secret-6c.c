/// Rooms for Tirun's Barrier reef
///       written by Ironman

#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
  ::create();
  set_properties((["water":1,"light":3,"night light":3]));
  set_long(
   "This appears to be some kind of chemical lab."
   " There is a large collection of pearls in a bucket on one of the tables."
   " Several beakers are filled with different chemicals and have pearls floating in them."
   " A large chart adorns one of the walls."
   " The bench along the south wall has several half-dissected clams spread out on it." 
  );

  set_exits(([
    "out":ROOMS2"secret-6b.c"
   ]));
  set_items(([
    "bucket":"There are pearls of almost every type here. It would appear Trydryill was attepting to learn how the pearls were rejuvenating the world's mana.",
    "beakers":"It seems Trydryill's mages were trying to reverse engineer the pearls. It's anyone's guess as to why.",
    "bench":"The remains of several sea creatures are splattered about the table. It seems most of them are clams.",
    "chart":"It reads--- \n\nWe have tracked down the source of the pearls to the magical clams."
    " Each clam can call its own class of pearls."
    " We have noticed the following trend in the pearls as we dissected them:"
    "\n\n White clam        white pearl"
    "\n\n Black clam        black pearl and all above pearls"
    "\n\n Blue clam         blue pearl and all above pearls"
    "\n\n Purple clam       purple pearl and all above pearls"
    "\n\n Rose clam         rose pearl and all above pearls"
    "\n\nWe haven't been able to dissect the star or blood clams. They appear to have magical seals that are too strong for us to break down. "
    "We can assume however that these are the strongest and rarest clams and must generate the rarest classes of pearls."
   ]));
  new(PEARLS"blood_clam.c")->move(this_object());
}
// Mob regeneration
void reset() {
  ::reset();
  MOB2"selection_lvl2.c"->execute_selection_lvl2(random(7),this_object());
}
