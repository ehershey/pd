//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The western side of the palace is reserved for the many servants that are required to keep the place running from day to day. Here the servants spend time relaxing during breaks. The corridor leads southeast to the entrance of the palace. The sun shines in through the leaves overhead.");
     set_night_long("The western side of the palace is reserved for the many servants that are required to keep the place running from day to day. Here the servants spend time relaxing during breaks. The corridor leads southeast to the entrance of the palace. The stars shine in through the leaves overhead.");
     set_exits(([
                "north"		: ELFROOM"palaceww2.c",
                "northwest"     : ELFROOM"servantq2.c",
		"southeast"	: ELFROOM"palacew1.c"	
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("servant"))
       new(ELFMOB"servant.c")->move(this_object());
     if(!present("servant 2"))
       new(ELFMOB"servant.c")->move(this_object());
}
