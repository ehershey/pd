#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^The kitchin within the palace%^RESET%^");
set_day_long("%^YELLOW%^This is a large kitchen where servants prepare the meals for the residents of the palace and in particular, the Queen.  It is usually busy during all hours.%^RESET%^");
set_night_long("%^YELLOW%^This is a large kitchen where servants prepare the meals for the residents of the palace and in particular, the Queen.  It is usually busy during all hours.%^RESET%^");
set_property("building",1);
set_items(([
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"west" : GCITY "gcity48.c",
]));
}

void reset() {
 ::reset();
if (!present("servant")) {
new(MOB "servant.c")->move(this_object());
new(MOB "servant.c")->move(this_object());
}
if (!present("cook")) {
new(MOB "cook.c")->move(this_object());
}
}

