//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The guest rooms of the palace are simply stunning. The wood of the floor looks as though it has simply grown up to create furniture. A bed is over in the corner with an exquisite blanket of fine silk . A table sits in the middle of the room with nothing but an ink bottle on it. The sun shines down from above.");
     set_night_long("The guest rooms of the palace are simply stunning. The wood of the floor looks as though it has simply grown up to create furniture. A bed is over in the corner with an exquisite blanket of fine silk . A table sits in the middle of the room that has many official looking documents on it. The moons and stars shine high above.");
     set_exits(([
                "southwest"     : ELFROOM"palaceee2.c"
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
