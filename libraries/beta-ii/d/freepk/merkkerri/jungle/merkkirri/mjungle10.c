#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Deep within the Merkkirri Jungle");
set_day_long("You can hear the distinct sound of voices to the west.  It also appears that an encampment has been set up there.  The Merkkirri often attack without provocation.  You've been warned...");
set_night_long("As you venture further into the jungle you notice the soft orange glow is actually a large bonfire.  You guess that there is an encampment or settlement to the west.  The Merkkirri often attack without provocation.  Consider yourself warned...");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"glow" : "The glow is coming from a large bonfire to the west.  It is quite bright in contrast to the dark jungle.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
]));
set_properties((["light" : 1, "night light" : 2,]));
set_exits(([
"east": MJUNGLE "mjungle9.c",
"west" : MJUNGLE "mjungle13.c",
"northwest" : MJUNGLE "mjungle14.c",
]));
}
