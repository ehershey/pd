#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Cleric's Tent");
set_long("This tent is kept dark and is lit only by the faint glow of candles.  Strange incense burns in the air.");
set_properties((["light" : 1, "indoors" : 1,]));
set_exits(([
"out" : MJUNGLE "mjungle15.c",
]));
set_items(([
"candles" : "A few candles burn in the tent giving the room a soft glow.",
"tent" : "The tent is well made and was woven by the Merkkirri.",
]));
}

void reset() {
::reset();
if(!present("cleric")) {
new(MOB "cleric.c")->move(this_object());
}
set_smell("default", "The aroma of incense lofts heavily in the tent.");
}
