#include <gcity.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
    ::create();
    set_short("%^YELLOW%^Top of the Southeast tower%^RESET%^");
    set_day_long("%^YELLOW%^From the top of the Southeast tower you can see just how vast the jungle surrounding the city is.  Far off to the east and to the southeast you see a dark and forbidding swamp.%^RESET%^");
    set_night_long("%^YELLOW%^From the top of the Southeast tower you can see just how vast the jungle surrounding the city is.  Far off to the east and to the southeast you see a dark and forbidding swamp.%^RESET%^");
    set_items(([
	"towers" : "The towers shoot high up into the sky and overlooking the jungle.",
	"jungle" : "The surrounding jungle is much larger than you imagined.",
	"swamp":"The swamp is rarely frequented by visitors.",
      ]));
    set_properties((["light" : 2, "night light" : 2,]));
    set_exits(([
	"down" : GCITY "gcity69.c",
      ]));
}

void reset() {
    ::reset();
    if (!present("royal guard")) {
	new(MOB "royalguard")->move(this_object());
	new(MOB "royalguard")->move(this_object());
    }
}

