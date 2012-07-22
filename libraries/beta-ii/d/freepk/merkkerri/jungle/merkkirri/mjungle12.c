#include <mjungle.h>
#include <daemons.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Deep within the Merkkirri Jungle");
    set_day_long("The jungle quickly turns into a swamp here.  Going in any direction other than where you came would be impossible.");
    set_night_long("Off to the far northwest you believe you see the glow of a fire or fires.  Here the ground quickly becomes unstable and you realize you have stepped into the beginnings of a swamp.  Continuing in any direction but the way you came would be impossible.");
    set_property("swamp",1);
    set_items(([
	"jungle" : "The jungle is dense and lush.  Shadows seems to be lurking within its depths.",
	"glow" : "The glow is probably caused from a campfire or several torches.  It is quite bright in contrast to the dark jungle.",
	({"leaves", "trees", "plants"}): "The plantlife here is drenched from the humidity.",
	"swamp" : "The jungle turns into a swamp that looks impossible to cross.",
      ]));
    set_properties((["light" : 2, "night light" : 1,]));
    set_exits(([
	"northeast": MJUNGLE "mjungle11.c",
      ]));
}

void reset() {
    ::reset();
    if (!present("viper")) {
	new(MOB "viper")->move(this_object());
	new(MOB "viper")->move(this_object());
	new(MOB "viper")->move(this_object());
    }
}
