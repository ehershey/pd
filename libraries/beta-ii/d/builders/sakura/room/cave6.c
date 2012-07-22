#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The cavern's path deviates to the west a significant amount here, while still continuing it's decent to the southwest, climbing back up slowly to the north. The passage once again narrows back even smaller then it was before, now being only six or seven metres across and three or four high. There is the occasional bone scattered around this area, but other then that it is free of features. The water stream drops away into a small hole here, and the path beyond becomes more rugged. The scratch marks continue to the southwest.");
    set_smell("default", "The cave smells wet and dank, accompanied by the stentch of rotting meat.");
    set_listen("default", "The cavern is quiet except for the rythemic drip of water from the roof.");

    set_items(([
	({"water", "trickle"}) : "The water disappears into a hole in the limestone.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "It's a bit hard to tell what these scratches are or what they mean, but it's not too hard to determine that they lead off to the southwest."
      ]));
    set_properties(([
	"light" : -1,
	"night light" : -2,
      ]));
    set_exits(([
	"north" : ROOMS"cave5.c",
	"southwest" : ROOMS"cave7.c"
      ]));
}
