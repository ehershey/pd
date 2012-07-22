#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit VAULT;

void create() {
::create();
set_short("%^YELLOW%^Within the Northeast guard tower%^RESET%^");
set_long("%^YELLOW%^The stairs of the tower continue to spiral around a large chamber located here on the third level.  The only way into the chamber is through a golden door adorned with large lionhead statues.  You may continue up the tower or back down to the sleeping quarter.%^RESET%^");
set_items(([
"stairs":"The stairs believe it or not go up or down.",
"door": "The door is large and elaborate with two statuesque golden lionheads protruding from the door.",
"chamber": "The chamber is well protected within the heart of the tower and probably belongs to someone important.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down": GCITY "gcity56.c",
"up": GCITY "gcity58.c",
"enter": GCITY "warroom.c",
]));
set_door("door", GCITY "warroom.c", "enter", "warlord's key");
set_string("door", "open", "You hope you're not making a huge mistake...");
}

void reset() {
 ::reset();
if(!present("royal guard")) {
new(MOB "royalguard.c")->move(this_object());
new(MOB "royalguard.c")->move(this_object());
}
set_open("door", 0);
set_locked("door", 1);
GCITY "warroom.c"->set_open("door", 0);
GCITY "warroom.c"->set_locked("door", 1);
}
