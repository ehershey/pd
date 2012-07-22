#include <std.h>
#include <nemar.h>

inherit ROOM;

void create() {
::create();
set_name("north wharf");
set_short("Northern Slope of the Wharf");
set_day_long("The grassy slope is mild, though it quickly turns to large " 
"rocks that decend into the great ocean.  A fisherman sits on a rock, singing "
"a sad tune.");

set_night_long("The rocks are lit by the brilliant glow of the walls.  Their "
"is a small shack where a human fisherman now sleeps.");

set_listen("default", "The waves of the ocean and the old fisherman are all that is heard.\n\nThe fisherman's tune is one of woe.  Something about a man that lost his woman while he was out at sea. To ease his pain he bought a tavern, sits in it, and drinks day after day.");

set_smell("default", "The strong smell of grass mixes with the salty smell of the ocean turning your stomach.");

set_items
  ((["fisherman" : "The fisherman returns your smile and continues his tune.",
    "shack" : "The shack leans up against the walls of Naej, home to an old fisherman.",
    "glow" : "The walls are radiant, as if the sun itself is reflecting off the walls."]));

set_properties
  ((["light"      : 3,
    "night light" : 2,
    "town"        : 1]));

set_exits
  ((["southwest" : NAEJ"dock.c",
     "south" : NAEJ"wharf.c"]));
}
