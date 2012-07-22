#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Atop the Northeast guard tower%^RESET%^");
set_day_long("%^YELLOW%^You stand atop the tower at the lookout point.  The tower guards can scan the nearby jungle for intruders from here as well as get a bit of fresh air.  The magnificant jungle surrounding Quixxiol is abound with life.%^RESET%^");
set_night_long("%^YELLOW%^You stand atop the tower at the lookout point.  The tower guards can scan the nearby jungle for intruders from here as well as get a bit of fresh air.  At night the city of Quixxiol glows dimly from torches, lanterns and fires.  You are truly amazed by the the golden city even if its origins are probably dark and twisted.%^RESET%^");
set_items(([
"stairs":"The stairs lead down towards the ground level.",
"jungle": "The jungle is much larger than you imagined.  You wonder just how much of it has never seen the likes of mankind.",
"volcano":"The volcano has always been a strong part of Merkkirri culture as it sybolizes the ending in the cycle of life.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down": GCITY "gcity58.c",
]));
}

void reset() {
 ::reset();
if(!present("towerguard")) {
new(MOB "swarmguard.c")->move(this_object());
}
}
