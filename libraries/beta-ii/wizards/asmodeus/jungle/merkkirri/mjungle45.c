#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The heart of the jungle");
set_day_long("The jungle is awake and full of life and a powerful scent of plantlife drifts through the air.  To the southwest you notice what appears to be a %^YELLOW%^BOLD%^golden%^RESET%^ tower darting high into the sky.  You see that the path you are following leads south to a small Merkkirri outpost.");
set_night_long("The jungle is awake and full of life even in the deepest night.  To the southwest you notice a faint orange glow from a settlement.  You see that the path you are following leads south to a small Merkkirri outpost.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"gold": "The glimmer of gold can be seen mixed within the jungle to the far southwest.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"glow": "The glow comes from a settlement to the southwest.  Considering the amount of light that can be seen, the city must be enormous.",
"outpost": "The outpost has been set up to serve as a lookout station and to guard against intruders.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([
"north": MJUNGLE "mjungle44.c",
"south": MJUNGLE "mjungle46.c",
]));
}

void reset() {
 ::reset();
}
