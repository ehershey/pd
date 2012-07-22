#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Deep within the Merkkirri Jungle");
set_long("The jungle has become very thick and you are becomming disoriented.  If one doesn't pay attention they could become lost in the vast jungle.  You notice a large cliff to the northeast.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"cliff" : "You think you can reach it by going northeast.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([
"east": MJUNGLE "mjungle30.c",
"northeast": MJUNGLE "mjungle40.c",
"west": MJUNGLE "mjungle35.c",
"southeast": MJUNGLE "mjungle31.c",
"south": MJUNGLE "mjungle33.c",
]));
add_invis_exit("northeast");
}

void reset() {
 ::reset();
   }
