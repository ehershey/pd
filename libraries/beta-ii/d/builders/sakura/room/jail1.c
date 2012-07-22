#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("This small alcove leads abrumptly to a dead end, with no features except a set of manacles attached to a heavy chain, which is in turn attached to the wall. There is fresh blood on the steel cuffs, along with a small puddle of the stuff on the ground of the cave. Clearly, this is some kind of prison area.");
    set_smell("default", "The repungnant stentch of rotting meat and blood overpowers your ofactory senses.");
    set_listen("default", "The cavern is quiet except for the rythemic drip of water from the roof.");
    set_items(([
	({"stone"}) : "The stone underfoot makes a sudden switch to a red-yellow coloured stone with occasional cracks of blue streaking through it.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "There are none here."
      ]));
    set_properties(([
	"light" : -1,
	"night light" : -2,
      ]));
    set_exits(([
	"northeast" : ROOMS"cave9.c",
      ]));
}

void reset() {
    if(!present("chains"))
	new(OBJ"chains.c")->move(this_object());
}
