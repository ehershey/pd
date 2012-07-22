#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Merkkirri Checkpoint");
set_day_long("You have reached a small outpost made of a bland grey stone that has been ravaged by weathering and is now covered with moss and slime.  The guards here are heavily armored and attack most intruders without provocation.");
set_night_long("You have reached a small outpost made of a bland grey stone that has been ravaged by weathering and is now covered with moss and slime.  The guards here are heavily armored and attack most intruders without provocation.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"gold": "The glimmer of gold can be seen mixed within the jungle to the far southwest.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"glow": "The glow comes from a settlement to the southwest.  Considering the amount of light that can be seen, the city must be enormous.",
"outpost": "The outpost has been set up to serve as a lookout station and to guard against intruders.",
"stone": "The stone is nothing spectacular but it does serve well in building the outpost and it shelters the guards well.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"north": MJUNGLE "mjungle45.c",
"southwest": MJUNGLE "mjungle47.c",
"enter": MJUNGLE "outpost1.c",
]));
new(MJUNGLE "building.c")->move(this_object());
}

void reset() {
 ::reset();

if(!present("guard")) {
new(MOB "gnollguardb.c")->move(this_object());
new(MOB "gnollguardb.c")->move(this_object());
new(MOB "gnollguardb.c")->move(this_object());
}
}
