#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("A jungle path");
set_day_long("You have come to a gateway into a city hidden within the deep Merkkirri jungle.  Amazingly enough, the entire city seems to be made of %^BOLD%^YELLOW%^gold%^RESET%^.  Undoubtedly this city doesn't like visitors.");
set_night_long("You have come to a gateway into a city hidden within the deep Merkkirri jungle.  Amazingly enough, the entire city seems to be made of %^BOLD%^YELLOW%^gold%^RESET%^.  Undoubtedly this city doesn't like visitors.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"gateway" : "The gateway is made of %^BOLD%^YELLOW%^gold%^RESET%^ as is the entire city.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
]));
new(MJUNGLE "gateway.c")->move (this_object());
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"northeast": MJUNGLE "mjungle47.c",
"gateway": GCITY "gcity1.c",
]));
}

void reset() {
 ::reset();
if(!present("guard")) {
new(MOB "gnollguardb.c")->move (this_object());
new(MOB "gnollguardb.c")->move (this_object());
}
}
