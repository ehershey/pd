#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Entrance hall of the Queens abode%^RESET%^");
set_day_long("%^YELLOW%^You stand inside the entrance chamber of the Queen's palace.  The inside walls resemble nothing of the outside as they are made of beautifully carved ivory murals.  Large fern type plants bring life to the room.%^RESET%^");
set_night_long("%^YELLOW%^You stand inside the entrance chamber of the Queen's palace.  The inside walls resemble nothing of the outside as they are made of beautifully carved ivory murals.  Large fern type plants bring life to the room.%^RESET%^");
set_items(([
"ferns":"The ferns are of a differing variety than would be found in this region.  How they have arrived here and maintened to live in adverse conditions is another matter.",
({"murals", "walls", "ivory"}):"The ivory murals adorning the walls depict incredible battles between the forces of good and evil.  Battles of angels and demons, light and dark, chaos and order.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"west" : GCITY "gcity49.c",
"northwest" : GCITY "gcity48.c",
"gates": GCITY "gcity33.c",
"southwest" : GCITY "gcity50.c",
]));
}

void reset() {
 ::reset();
if (!present("royal guard")) {
new(MOB "royalguard")->move(this_object());
new(MOB "royalguard")->move(this_object());
}
}

