#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("A jungle path");
set_day_long("The jungle is awake and full of life and a powerful scent of plantlife drifts through the air.  To the southwest you notice what appears to be a %^YELLOW%^BOLD%^golden%^RESET%^ tower darting high into the sky and it is becomming more and more apparent that you are approaching a lost city of the Merkkirri.  The path runs to the southwest and northeast.");
set_night_long("The jungle is awake and full of life and a powerful scent of plantlife drifts through the air.  To the southwest you notice what appears to be a %^YELLOW%^BOLD%^golden%^RESET%^ tower darting high into the sky and it is becomming more and more apparent that you are approaching a lost city of the Merkkirri.  The path runs to the southwest and northeast.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"gold": "The glimmer of gold can be seen mixed within the jungle to the far southwest.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"glow": "The glow comes from a settlement to the southwest.  Considering the amount of light that can be seen, the city must be enormous.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"northeast": MJUNGLE "mjungle46.c",
"southwest": MJUNGLE "mjungle48.c",
]));
}

void reset() {
 ::reset();
}
