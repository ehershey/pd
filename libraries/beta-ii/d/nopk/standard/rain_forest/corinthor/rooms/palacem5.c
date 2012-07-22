//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The central passage of the palace ends here, with the north opening out to the throne room. The trees sprouting up create a solid wall, with a few alcoves for guards to stand in. The leaves above let in plenty of sunlight, and the floor beneath is plainly the cut bark of a giant tree.");
     set_night_long("The central passage of the palace ends here, with the north opening out to the throne room. The trees sprouting up to either side create effective walls. On either side is an alcove for guards to stand in. The leaves above sway in the breeze, opening out to the night sky filled with stars.");
     set_exits(([
		"north"		: ELFROOM"throne.c",
		"south"		: ELFROOM"palacem4.c"
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
     if(!present("knight 3"))
       new(ELFMOB"knight.c")->move(this_object());
}


