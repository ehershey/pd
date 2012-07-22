#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;
void init() {
    ::init();
}

void create() {
::create();
set_short("%^YELLOW%^A hidden altar%^RESET%^");
set_long("%^YELLOW%^So this is where the Queen hides... A hidden altar has been constructed here to worship the lord of demons, Asmodeus.  Very few people, if anyone, has ever seen this chamber.%^RESET%^");
set_items(([
"altar":"The altar is made of black adamantite and glistens in the gold and violet lighting.  You notice it is filled with blood.",
]));
set_properties((["light" : 1, "indoors" : 1,]));
set_property("building",1);
set_exits(([
"southeast": GCITY "gcity76.c",
]));
new(GCITY "bloodaltar.c")->move(this_object());
}
void reset() {
 ::reset();
if(!present("shallzaea")) {
new(MOB "queen.c")->move(this_object());
}
}
