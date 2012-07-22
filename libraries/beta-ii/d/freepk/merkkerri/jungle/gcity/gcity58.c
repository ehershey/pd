#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Within the Northeast guard tower%^RESET%^");
set_long("%^YELLOW%^You are near the top of the tower.  The stairs continue up to the lookout or you can go back down.  As you peer outside you can better see the immense size of the jungle.  You also see a large volcano off in the distance.%^RESET%^");
set_items(([
"stairs":"The stairs lead up into the higher levels of the tower or down towards the ground level.",
"jungle": "The jungle is much larger than you imagined.  You wonder just how much of it has never seen the likes of mankind.",
"volcano":"The volcano has always been a strong part of Merkkirri culture as it sybolizes the ending in the cycle of life.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down": GCITY "gcity57.c",
"up": GCITY "gcity59.c",
]));
}

void reset() {
 ::reset();
}
