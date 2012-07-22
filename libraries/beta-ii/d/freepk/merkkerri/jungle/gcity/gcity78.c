#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^Chambermaid's living quarters%^RESET%^");
set_day_long("%^YELLOW%^You stand within the chambermaid's living quarters.  Why the queen keeps them around is a mystery in itself.  The room is fairly nice with a large mirror, beds and dressers.%^RESET%^");
set_night_long("%^YELLOW%^You stand within the chambermaid's living quarters.  Why the queen keeps them around is a mystery in itself.  The room is fairly nice with a large mirror, beds and dressers.%^RESET%^");
set_property("building",1);
set_items(([
"mirror":"A full size mirror you could use to admire yourself in.",
"beds":"The beds look rather soft and cozy.",
"dressers":"The dressers are filled with frilly chambermaid clothes.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"down" : GCITY "gcity67.c",
]));
}

void reset() {
 ::reset();
if (!present("blonde chambermaid")) {
new(MOB "blmaid.c")->move(this_object());
}
if (!present("brunette chambermaid")) {
new(MOB "brmaid.c")->move(this_object());
}
}

