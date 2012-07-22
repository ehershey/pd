//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The guest rooms of the palace are simply stunning. The furniture looks like it has been grown rather than cut. The bed in the corner is covered with exquisite silk sheets. A table sits in hte middle of the room, and is bare except for a lonely ink bottle. The sun shines bright in the sky above.");
     set_night_long("The guest rooms of the palace are simply stunning. The furniture looks like it has been grown rather than cut. The bed in the corner is covered with exquisite silk sheets. A table sits in the middle of the room and is covred with official looking documents. The stars shine in the night sky.");
     set_exits(([
                "southwest"     : ELFROOM"palaceee1.c"
                ]));
     set_items(([
	"table"		: "It's a table, with an ink bottle. Nothing overly special.",
	"documents"	: "Various official documents of the elven court at Corminthor, not important to non-nobles."
        ]));
}

void reset() {
   ::reset();
     if(!present("noble"))
       new(ELFMOB"noble.c")->move(this_object());
}
