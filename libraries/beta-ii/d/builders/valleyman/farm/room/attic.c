//Valleyman

#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1, ]) );
        set_short("Attic of the Farmhouse");
        set_day_long("There is little light in this room, the only source is from a few cracks in the roof making it seem like this otherwise dim room look bright. There are many differnet sized boxes here and a few other pieces of junk not used.");
        set_night_long("The moonlight shining in through the cracks in the roof make it seem like this room is bright. Many different sized boxes are scattered around with other bits of junk not used in the house.");

        set_items(( [
                "boxes" : "Boxes of items not needed or forgotten about",
		"cracks" : "Cracks in the roof let light in making the otherwise dim room look bright.",
                ]));

        set_exits(([
                "down" : ROOMS"house3.c",
                ]));

}
