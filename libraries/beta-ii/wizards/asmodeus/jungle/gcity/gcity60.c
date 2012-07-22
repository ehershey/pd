#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^The royal dining hall%^RESET%^");
set_day_long("%^YELLOW%^You have entered the dining hall of the Queen.  Lavish carpets hang upon the walls and great decorative statues adorn the room.  The dining table is quite large, taking up much of the room.  The only exit is back south.%^RESET%^");
set_night_long("%^YELLOW%^You have entered the dining hall of the Queen.  Lavish carpets hang upon the walls and great decorative statues adorn the room.  The dining table is quite large, taking up much of the room.  The only exit is back south.%^RESET%^");
set_property("building",1);
set_items(([
"carpets": "The carpets are used to insulate the large dining hall as well as keep the room lively.  They probably took several people to move.",
"statues": "The Merkkirri Queen seems to adore statues and this room is no different.  The statues, eight in all, show various Merkkirri warriors in differing positions.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
new(GCITY "table.c")->move(this_object());
set_exits(([
"south" : GCITY "gcity48.c",
]));
}

void reset() {
 ::reset();
if (!present("assailant")) {
new(MOB "shadowass.c")->move(this_object());
}
}

