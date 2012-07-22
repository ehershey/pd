#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The center of a Merkkirri encampment");
set_day_long("You are standing in the center of a Merkkirri encampment. A large bonfire burns in the center of the camp where it is used to cook meals and provide light at night.  A large tent stands here with a flag waving slightly in the damp jungle air.");
set_night_long("You are standing in the center of a Merkkirri encampment. A large bonfire burns in the center of the camp where it is used to cook meals and provide light at night.  A large tent stands here with a flag waving slightly in the damp jungle air.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"shadows" : "You think you see shadows stirring within the dark jungle.  You decide it is best to be cautious here.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"encampment" : "The camp has been built to surround the bonfire and its warlord.  Tents can be seen north, west and south of here.",
"tent" : "The tent standing at the center of the camp is by far the most splendid of the tents.  Whoever resides inside must be in command of the encampment.",
"flag" : "The flag is of a %^BOLD%^BLACK%^black%^RESET%^ bird, perhaps a falcon, residing on a %^YELLOW%^golden%^RESET%^ backround.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"north": MJUNGLE "mjungle14.c",
"south": MJUNGLE "mjungle16.c",
"east": MJUNGLE "mjungle10.c",
"west" : MJUNGLE "mjungle15.c",
"enter" : MJUNGLE "tent1.c",
"southwest": MJUNGLE "mjungle17.c",
]));
}

void reset() {
::reset();
if(!present("guard")) {
new(MOB "gnollguarda.c")->move(this_object());
new(MOB "gnollguarda.c")->move(this_object());
new(MOB "gnollguarda.c")->move(this_object());
}
if(!present("bonfire"))
new(MJUNGLE "bonfire.c")->move(this_object());
if(!present("tent"))
new(MJUNGLE "tent_obj1.c")->move(this_object());
}
