#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Deep within the Merkkirri Jungle");
set_long("The jungle has become very thick and you are becomming disoriented.  To the far south and southeast lies a swamp.  A small trail leads to the south and has been nearly overgrown by the surrounding plants.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"path" : "The path looks old and probably hasn't been used in some time.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([
"southeast": "/wizards/asmodeus/swamp/swamp1.c",
"northwest": MJUNGLE "mjungle38.c",
]));
}

void reset() {
 ::reset();
}
