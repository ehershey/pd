#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Deep within the Merkkirri Jungle");
set_day_long("The jungle has become very thick and you are becomming disoriented.  If one doesn't pay attention they could become lost in the vast jungle.");
set_property("forest",1);
set_night_long("The jungle has become very thick and you are becomming disoriented.  If one doesn't pay attention they could become lost in the vast jungle.  You hear strange chanting noises coming from the jungle to the southwest.");
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"southwest" : "You think you might be able to go that direction after all.",
]));
add_invis_exit("southwest");
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([
"east": MJUNGLE "mjungle29.c",
"northwest": MJUNGLE "mjungle36.c",
"southwest": MJUNGLE "mjungle44.c",
"north": MJUNGLE "mjungle33.c",
"southeast": MJUNGLE "mjungle28.c",
]));
}

void reset() {
 ::reset();
if (!present("spider")) {
new(MOB "glspider")->move(this_object());
}
if (!present("viper")) {
new(MOB "viper")->move(this_object());
   }
}
