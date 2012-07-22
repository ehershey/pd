#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit VAULT;

void create() {
::create();
set_short("%^YELLOW%^The Queen's chamber%^RESET%^");
set_long("%^YELLOW%^You have entered the Queen's chamber.  The room is a stark contrast to the rest of the city as the room is painted %^BOLD%^BLUE%^dark blue%^YELLOW%^.  A large bed lies in the center of the room and several dressers and personal belongings decorate the room.");
set_items(([

"door": "The door is made of obsidian and bears the royal symbol of the Queen.",
"bed":"The bed is extremely soft and comfortable.",
"dressers":"The dressers hold several valuable outfits but selling them would be nearly impossible as only the Merkkirri would appreciate their beauty and no Merkkirri would ever buy something belonging to the Queen.",
"belongings":"The belongings probably have value but selling them would be nearly impossible as only the Merkkirri would apreciate their beauty and no Merkkirri would ever buy something belonging to the Queen.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"out": GCITY "gcity82.c",
]));
set_door("door", GCITY "gcity82.c", "out", "ruby key");
set_string("door", "open", "You open the door leading outside the chamber.");
}

void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
GCITY "gcity82.c"->set_open("door", 0);
GCITY "gcity82.c"->set_locked("door", 1);
if(!present("Myrrynndyll"))
new(MOB "myrrynndyll.c")->move(this_object());
}
