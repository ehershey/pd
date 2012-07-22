#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("%^YELLOW%^The royal library%^RESET%^");
set_day_long("%^YELLOW%^This rather extensive library is the work of Shallzaea.  Most of the books here tell accounts of her great triumph over the previous ruler and of the dark arts.  An old sage can somtimes be found here combing the library for knowledge or tidying up the room.%^RESET%^");
set_night_long("%^YELLOW%^This rather extensive library is the work of Shallzaea.  Most of the books here tell accounts of her great triumph over the previous ruler and of the dark arts.  An old sage can somtimes be found here combing the library for knowledge or tidying up the room.%^RESET%^");
set_property("building",1);
set_items(([
(({"books", "tomes", "tome", "book", "library"})): "The library will soon tell of Quixxiol, the Queen and how the Merkkirri become the bloodlusted followers of Asmodeus.",
]));
set_properties((["light" : 2, "indoors" : 2,]));
set_exits(([
"east": GCITY "gcity51.c",
]));
}

void reset() {
 ::reset();
if (!present("sage")) {
new(MOB "elderly.c")->move(this_object());
}
}

