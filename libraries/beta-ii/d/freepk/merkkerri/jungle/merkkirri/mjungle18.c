#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
set_short("Deep within the Merkkirri Jungle");
set_day_long("The jungle quickly turns into a swamp to the south and southeast.  Travelling in either direction would be impossible.  The thick tropical jungle surrounds you in the other directions.");
set_night_long("Off to the northeast you see the distant glow of a fire.  A swamp dominates the south and southeastern directions while the jungle dominates the rest of the landscape.  The swamp looks impossible to pass.");
set_property("swamp",1);
set_items(([
"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
"glow" : "The glow is probably caused from the bonfire.  It is quite bright in contrast to the dark jungle even from this far away.",
({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
"swamp" : "The jungle turns into a swamp that looks impossible to cross.",
]));
set_properties((["light" : 1, "night light" : 1,]));
set_exits(([
"northeast": MJUNGLE "mjungle17.c",
"northwest": MJUNGLE "mjungle20.c",
"west": MJUNGLE "mjungle19.c",
]));
}

void reset() {
 ::reset();
   if (!present("viper")) {
      new(MOB "viper")->move(this_object());
   }
if (!present("parrot")) {
new(MOB "bbparrot")->move(this_object());
}
}
