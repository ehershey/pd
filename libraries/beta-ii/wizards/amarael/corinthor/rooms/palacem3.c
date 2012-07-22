//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The main hall of the palace stretches on to the north and south, with trees on either side creating the walls. Above the sun shines through the leaves of the trees, bringing light and warmth. On either wall is a guardpost reserved for the knights of the forest.");
     set_night_long("The main hall of the palace stretches on to the north and south, with trees on either side creating the walls. Above the night sky stretches forever, with the stars and moons hanging in the abyss. On either wall is a guardpost reserved for the knights of the forest.");
     set_exits(([
		"north"		: ELFROOM"palacem4.c",
		"south"		: ELFROOM"palacem2.c"
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("knight"))
       new(ELFMOB"knight.c")->move(this_object());
     if(!present("knight 2"))
       new(ELFMOB"knight.c")->move(this_object());
}
