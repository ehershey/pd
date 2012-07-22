#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^The royal throne room of Queen Shallzaea%^RESET%^");
set_day_long("%^YELLOW%^You stand in the royal throne room of Queen Shallzaea.  The room is made entirely of gold and has been sculpted so that the walls and ceiling close in along giant pillars giving you a feeling of being trapped within the rip cage of some giant creature.  Giant dias's filled with oil have been set ablaze producing eerie green flames.  Never before have you seen such extravagance.%^RESET%^");
set_night_long("%^YELLOW%^You stand in the royal throne room of Queen Shallzaea.  The room is made entirely of gold and has been sculpted so that the walls and ceiling close in along giant pillars giving you a feeling of being trapped within the rip cage of some giant creature.  Giant dias's filled with oil have been set ablaze producing eerie green flames.  Never before have you seen such extravagance.%^RESET%^");
set_items(([
"dias":"The dias's are filled with an oil produced naturally in the regions near the swamp.  The flames produces from this oil appear %^GREEN%^green%^RESET%^.",
({"walls", "ceiling", "pillars", "rip cage"}):"The room has been crafted in a way that you feel trapped within the belly of a giant beast.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"west" : GCITY "gcity53.c",
"north" : GCITY "gcity52.c",
"southeast": GCITY "gcity49.c",
]));
add_invis_exit("north");
new(GCITY "throne.c")->move(this_object());
}

void reset() {
 ::reset();
if (!present("shallzaea")) {
new(MOB "queenill.c")->move(this_object());
}
if (!present("royal guard")) {
new(MOB "royalguard")->move(this_object());
new(MOB "royalguard")->move(this_object());
}
}

