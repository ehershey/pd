#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("This part of the cavern seems to be almost level, with the tunnel sloping up to the north and dipping down to the south. The stone here continues the bleak, featureless grey that is observed higher in the cavern, although the ground is rougher having been denied the luxury of decades of smoothing by running water. The trail of scratch marks trail deeper into the cavern, to the south, along with a few spots of blood.");    set_smell("default", "The repungnant stentch of rotting meat overpowers your ofactory senses.");
    set_smell("default", "The repungnant stentch of rotting meat overpowers your ofactory senses.");
    set_listen("default", "The cavern is as silent as a tomb.");
    set_items(([
	({"stone"}) : "The stone has gotten progressively darker as one decends and is now almost black.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "The scratch marks lead off to the south."
      ]));
    set_properties(([
	"light" : -1,
	"night light" : -2,
      ]));
    set_exits(([
	"north" : ROOMS"cave7.c",
	"south" : ROOMS"cave9.c",
      ]));
}
