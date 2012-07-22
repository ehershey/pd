#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Within the Merkkirri Jungle");
set_day_long("You can distinctly hear voices coming from the west.  The Merkkirri are not known for their hospitality.  Perhaps turning back now might not be such a bad idea.");
set_night_long("The glowing to the west is quite bright.  It must be quite a fire to light the area.  The Merkkirri are not known for their hospitality.  Perhaps turning back now might not be such a bad idea.");
set_property("forest",1);
set_items(([
"jungle" : "The jungle is dense and lush.  There appears to be some stonework that has been overgrown to the southeast.",
"glow" : "The glow is probably caused from a campfire or several torches.  It is quite bright in contrast to the dark jungle.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
]));
set_properties((["light" : 2, "night light" : 2,]));
set_exits(([
"northeast": MJUNGLE "mjungle7.c",
"southwest" : MJUNGLE "mjungle12.c",
"southeast" : MJUNGLE "msquare.c",
]));
add_invis_exit("southeast");
}

void reset() {
 ::reset();
   if (!present("guard")) {
      new(MOB "gnollguard.c")->move(this_object());
      new(MOB "gnollguard.c")->move(this_object());
   }
   if (!present("warrior"))
      new(MOB "gnollwarrior")->move(this_object());
}
