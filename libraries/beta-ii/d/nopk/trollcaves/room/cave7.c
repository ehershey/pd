#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The cavern's path splits in three directions here, with all three paths being completely natural divisions. The larger of the two pathways climbs up to the northeast, with the second larger of the three sloping off to the south, whereas the smallest of the three dips off to the southeast. The ceiling here is devoid of limestone, with the entire passage being the same grey stone as seen in higher parts of the tunnel although it is nearly black by this depth. The same scraping claw marks seen to the northeast disappear down to the south.");
    set_smell("default", "The cave smells wet and dank, accompanied by the stentch of rotting meat.");
    set_listen("default", "The cavern is quiet except for the rhythmic drip of water from the roof.");
    set_items(([
	({"stone"}) : "The stone has gotten progressively darker as one decends and is now almost black.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "The scratch marks lead off to the south."
      ]));
    set_properties(([
	"light" : -1,
	"night light" : -2,
      ]));
    set_exits(([
	"northeast" : ROOMS"cave6.c",
	"south" : ROOMS"cave8.c",
	"southeast" : ROOMS"deadend1.c"
      ]));
}

void reset() {
    if(!present("troll"))
	new(MOB"troll.c")->move(this_object());
}
