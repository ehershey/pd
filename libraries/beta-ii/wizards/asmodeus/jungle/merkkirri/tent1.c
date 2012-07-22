#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Within the Warlord's tent");
set_long("You have entered a wonderful tent filled with lush furniture and magnificent decorations.  This is also where Treggeth the Warlord resides.  Few outsiders have come here and ever made it out alive.");
set_properties((["light" : 3, "indoors" : 3,]));
set_exits(([
"out" : MJUNGLE "mjungle13.c",
]));
set_items(([
"furniture" : "The furnishings in the tent are well made but not the kind of thing you'd want to try to sell yourself.",
"decorations" : "The decorations look nice but are probably not worth a great deal of money.",
"tent" : "The tent is well made and was woven by the Merkkirri.",
]));
}

void reset() {
::reset();
if(!present("treggeth")) {
new(MOB "treggeth.c")->move(this_object());
}
if (!present("warrior")) {
   new(MOB "gnollwarrior.c")->move(this_object());
   new(MOB "gnollwarrior")->move(this_object());
}
if (!present("kezruul"))
   new(MOB "kezruul")->move(this_object());
}
