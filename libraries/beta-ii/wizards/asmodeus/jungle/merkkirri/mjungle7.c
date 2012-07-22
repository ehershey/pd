#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Within the Merkkirri Jungle");
set_day_long("As you venture further into the jungle you begin to hear the sound of voices to the west.  The Merkkirri are not known for their hospitality.  Perhaps turning back now might not be such a bad idea.");
set_night_long("As you venture further into the jungle you notice a soft orange glow coming from the west.  You guess that there is an encampment or settlement in that direction.  The Merkkirri are not known for their hospitality.  Perhaps turning back now might not be such a bad idea.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"glow" : "The glow is probably caused from a campfire or several torches.  It is quite bright in contrast to the dark jungle.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([
"east": MJUNGLE "mjungle5.c",
"west" : MJUNGLE "mjungle9.c",
"southwest" : MJUNGLE "mjungle11.c",
]));
}
