#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The hillside opens up to a spacious cavern entrance, fifteen or sixteen metres across and half that high. A great many pointed stalagmites and stalactites hang from the roof and grow from the floor near the mouth of the cavern, giving the impression of an open mouth full of fangs. A small trickle of water creeps through the lowest part of this cave, fed from a stream nearby. As the water passes through the entrance it is stained brown from the dust and dirt which is blown in by the wind. The floors and walls are a dull grey stone, washed smooth by the years of flowing water. There is a thin layer of dust and dirt which has gathered around the entrance of the cave, however it is not even and clean as time would have made it; it appears to have been disturbed recently. The ceiling of the cavern is a patchwork of the grey stone seen on the walls and floor and light white limestone.");
    set_smell("default", "The musty smell of the cave wafts up from the depths.");
    set_listen("default", "All seems quiet in the cavern.");

    set_items(([
	({"hillside", "hill"}) : "The hillside is rather unremarkable except for this very cave, although it is covered in a layer of green grass and dotted with the occasional tree stump.",
	({"stalagmites", "stalagmite", "stalactite","stalactites", "teeth", "fangs"}) : "The collections of rock formations have given the cavern the appearance of a large, predatory mouth of teeth. And the spikes are rather sharp; it would not take much effort to injure oneself on the rather dangerous rocks.",
	({"water", "trickle"}) : "The water is stained a light brown from the dust which is blown in from the path outside. The flow is small, really, but it looks that at some point at least it was larger.",
	({"dust", "dirt", "layer"}) : "This spartan sprinkling of dust has apparently been disturbed recently, and whoever or whatever did it must have had rather large feet.",
	({"opening", "open"}) : "The opening of the cavern is wide and rather menacing.",
	({"ceiling"}) : "Upon closer inspection it would appear that the cavern's ceiling is not altogether stable, and several cracks run along it's length. The white limestone seems particularly weaker then the grey stone."
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
	"indoors" : 1,
      ]));
    set_exits(([
	"out" : ROOMS"exit.c", // Add an exit room here when this small area is added.
	"south" : ROOMS"cave2.c"

      ]));
}
