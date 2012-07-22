#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The cavern slowly swings downwards and slightly to the east as it decends, the 'teeth' of the entrace left far behind. The passage also narrows somewhat as it decends, widening as it gets closer to the opening. As the passage decends the angle of decent begins to increase slightly, the trickle of water speeding up slightly in response. There are curiously no stalagmites or stalactites here, as opposed to the entrance which is full of them. There are some scratch marks on the floor here, leading deeper into the cavern.");
    set_smell("default", "The cave smells musty and dank.");
    set_listen("default", "The cavern is quiet except for some distant dripping water.");

    set_items(([
	({"teeth", "entrance"}) : "The teeth of the entrance cast a menacing shadow into the cavern.",
	({"water", "trickle"}) : "The water begins to clear as it decends, slowly returning to a normal transparency as the dirt settles.",
	({"opening", "open"}) : "The opening of the cavern is wide and rather menacing.",

	({"scratch marks", "marks", "scratch", "scratches"}) : "These scratch marks appear to be consistant with a large, clawed creature dragging a heavy load. They clearly lead deeper into the cavern."
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"north" : ROOMS"cave1.c",
	"south" : ROOMS"cave3.c"
      ]));
}
