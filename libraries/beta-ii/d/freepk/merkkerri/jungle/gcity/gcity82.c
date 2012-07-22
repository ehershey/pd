#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit VAULT;

void create() {
::create();
set_short("%^YELLOW%^Outside the Queen's bedroom%^RESET%^");
set_long("%^YELLOW%^The stairs of the tower have taken you to a large obsidian door.  The royal symbol of the Queen marks the door.  You also notice a large and quite complex lock sealing the door shut.%^RESET%^");
set_items(([
"door": "The door is made of obsidian and the symbol engraved into the door probably took weeks to complete.",
"chamber": "The chamber is well protected within the heart of the tower and probably belongs to someone important.",
"lock":"The lock looks complex.  A key is needed or a rogue...",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down": GCITY "gcity81.c",
"enter": GCITY "gcity83.c",
]));
set_door("door", GCITY "gcity83.c", "enter", "ruby key");
set_string("door", "open", "You feel an overwhelming rush of evil flow through the door...");
}

void reset() {
 ::reset();
if(!present("royal guard")) {
new(MOB "royalguard.c")->move(this_object());
new(MOB "royalguard.c")->move(this_object());
}
set_open("door", 0);
set_locked("door", 1);
GCITY "gcity83.c"->set_open("door", 0);
GCITY "gcity83.c"->set_locked("door", 1);
}
