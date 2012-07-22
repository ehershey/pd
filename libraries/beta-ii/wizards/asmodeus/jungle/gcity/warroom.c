#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit VAULT;

void create() {
::create();
set_short("%^YELLOW%^The Warlords chamber%^RESET%^");
set_long("%^YELLOW%^You have entered the chamber of the great Merkkirri Warlord, Samul Ku'thull.  A heartless, bloodthirsty commander who has often slaughtered his own troops to display his animalistic behavior to his enemies.  While in many cultures this may seem terrible, the Merkkirri people adore Samul and his actions.  The chamber is well decorated and looks quite comfortable although Samul's presence  when here might change your opinion.%^RESET%^");
set_items(([

"door": "The door is large and elaborate with two statuesque golden lionheads protruding from the door.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"out": GCITY "gcity57.c",
]));
set_door("door", GCITY "gcity57.c", "out", "warlord's key");
set_string("door", "open", "You open the door leading outside the chamber.");
}

void reset() {
 ::reset();
set_open("door", 0);
set_locked("door", 1);
GCITY "gcity57.c"->set_open("door", 0);
GCITY "gcity57.c"->set_locked("door", 1);
if(!present("Samul Ku'Thull"))
new(MOB "samul.c")->move(this_object());
}
