#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The cavern here slopes from the northwest to the south, its angle of decent increasing towards the south. The eastern wall here bears some heavy scratching, as though from some animal attempting to sharpen its claws. The trail of scratches on the floor leads to the southeast and is somewhat harder to discern, as it is marred by other scratches which mull about. The walls widen here considerably, forming a substancial bulge in the passage. There is evidence that someone is or was recently living here; a burned down campfire in the centre of this room but away from the water, a stockpile of wood to one side, and a rather large pile of bones to another.");
    set_smell("default", "The cave smells wet and dank, accompanied by the light smell of rotting meat.");
    set_listen("default", "The cavern is quiet except for the rhythmic drip of water from the roof.");

    set_items(([
	({"east wall", "eastern wall", "scratching", "wall"}) : "These claws appear to be roughly the same size and shape as on trolls. Also, it is typical behaviour of trolls to sharpen their claws on stone before hunting.",
	({"campfire"}) : "This fire has been extinguished for many weeks now. The smoke would have disappeared up through one of the many holes in the limestone ceiling.",
	({"water", "trickle"}) : "The water preforms gravity's bidding, sloping off to the southeastern part of the cavern.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "It's a bit hard to tell what these scratches are or what they mean, but it's not too hard to determine that they lead off to the southeast."
      ]));
    set_properties(([
	"light" : 0,
	"night light" : -1,
      ]));
    set_exits(([
	"northwest" : ROOMS"cave4.c",
	"south" : ROOMS"cave6.c"
      ]));
}

void reset() {
    if(!present("body"))
	new(OBJ"body.c")->move(this_object());
    if(!present("troll"))
	new(MOB"troll.c")->move(this_object());
}
