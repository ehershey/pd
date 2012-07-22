#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("The western part of the encampment");
set_day_long("You are standing in the western part of the Merkkirri encampment.  A black tent stands here and to the east you notice a large bonfire burning.");
set_night_long("You are standing in the western part of the Merkkirri encampment.  A black tent stands here and to the east you notice a large bonfire burning.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"bugs" : "Insects float around you waiting for a moment to take a bite.",
"shadows" : "You think you see shadows stirring within the dark jungle.  You decide it is best to be cautious here.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"encampment" : "The camp has been built to surround the bonfire and its warlord.  You are standing in the western part of the camp.",
"tent" : "This tent is quite small and made of black fabric.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"east": MJUNGLE "mjungle13.c",
"enter" : MJUNGLE "tent3.c",
]));
}

void reset() {
 ::reset();
   if(!present("guard")) {
      new(MOB "gnollguarda.c")->move(this_object());
   }
   if(!present("tent"))
new(MJUNGLE "tent_obj3.c")->move(this_object());
}
