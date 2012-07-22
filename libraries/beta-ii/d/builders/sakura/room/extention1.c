#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The extention work to the cavern ends after only a few short metres. There has been a massive cave-in here recently, and huge slabs of stone and wood block the path further north. There are small stones and pebbles laying about all over the ground here, rubble from the collapse. The slabs that have fallen are vast, each certain to weigh over several tonnes each and impossible to move.");
    set_smell("default", "The cave smells musty and dank.");
    set_listen("default", "The cavern is quiet except for the rythemic drip of water from the roof.");

    set_items(([
	({"cave-in", "cave in", "cavein"}) : "There has been a massive cave-in here and all access to the extention work past this point is blocked. It would appear that the shoddy workmanship of the cave was it's downfall; a casual examination reveals one of the support beams simply slipped out of it's poorly manufactured join and bought the whole tunnel down with it.",
	({"stones", "stone", "small stones", "small stone", "pebble", "pebbles"}) : "These are simply rubble from the cave in and are of no consequence.",
	({"water", "trickle"}) : "The water preforms gravity's bidding, sloping off to the southeastern part of the cavern.."
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"west" : ROOMS"cave4.c",
      ]));
}
