#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Gates to the Queens main palace%^RESET%^");
set_day_long("%^YELLOW%^You stand at the foot of large golden gates that lead into the Queen's abode.  The palace is beyond splendid and everything looks perfect.  You begin to wonder whoever or whatever created the city of gold.%^RESET%^");
set_night_long("%^YELLOW%^You stand at the foot of large golden gates that lead into the Queen's abode.  The palace is beyond splendid and everything looks perfect.  You begin to wonder whoever or whatever created the city of gold.%^RESET%^");
set_items(([
"gates": "The gates are made entirely of gold and are shaped in the form of bones interlocking by contorted joints.",
({"palace", "abode"}) : "The main part of the palace houses the Queen of the Merkkirri.  It is far grander than any of the surrounding city.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": GCITY "gcity21.c",
"gates": GCITY "gcity47.c",
]));
}

void reset() {
 ::reset();
if(!present("royal guard")) {
new(MOB "royalguard.c")->move(this_object());
new(MOB "royalguard.c")->move(this_object());
}
}
