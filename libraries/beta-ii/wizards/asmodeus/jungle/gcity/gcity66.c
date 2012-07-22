#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^The servants living quarters%^RESET%^");
set_day_long("%^YELLOW%^This chamber has been converted into a bedroom for several servants.  The 'rooms' are divided by curtains and considering the rest of the palace splender, the servants have it rough.  A window looks out to the west where far off in the distance the warm tropical waters glisten in the sunlight.%^RESET%^");
set_night_long("%^YELLOW%^This chamber has been converted into a bedroom for several servants.  The 'rooms' are divided by curtains and considering the rest of the palace splender, the servants have it rough.  A window looks out to the west where far off in the distance the warm tropical waters twinkle in the moonlight.%^RESET%^");
set_property("building",1);
set_items(([
"curtains":"The curtains are cheap and flimsy.  They offer only enough privacy to keep others from seeing inside.",
"window":"The window gives a view of the surrounding jungle and the ocean off to the far west.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"southeast" : GCITY "gcity63.c",
]));
}

void reset() {
 ::reset();
if (!present("servant")) {
new(MOB "servant2.c")->move(this_object());
new(MOB "servant2.c")->move(this_object());
new(MOB "servant2.c")->move(this_object());
}
}

