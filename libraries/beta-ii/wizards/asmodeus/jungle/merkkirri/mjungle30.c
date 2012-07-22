#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Deep within the Merkkirri Jungle");
set_long("The jungle has become very thick and you are becomming disoriented.  If one doesn't pay attention they could become lost in the vast jungle.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([
"west": MJUNGLE "mjungle34.c",
"southeast": MJUNGLE "mjungle26.c",
"south": MJUNGLE "mjungle31.c",
"east": MJUNGLE "mjungle27.c",
]));
}

void reset() {
 ::reset();
if (!present("parrot")) {
new(MOB "bbparrot")->move(this_object());
}
if (!present("ape")) {
new(MOB "redape")->move(this_object());
   }
}
