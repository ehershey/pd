//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The western side of the palace is reserved for the many servants that are required to keep the place running from day to day. At all times of the day or night servant's spend their short amounts of time off relaxing here. Although a little more plain than the rest of the palace, it is still quite beautiful.");
     set_night_long("The western side of the palace is reserved for the many servants that are required to keep the place running from day to day. At all times of the day or night servant's spend their short amounts of time off relaxing here. Although a little more plain than the rest of the palace, it is still quite beautiful, especially so with the stars overhead.");
     set_exits(([
                "northeast"     : ELFROOM"palacew3.c",
                "northwest"     : ELFROOM"servantq1.c",
		"south"		: ELFROOM"palaceww1.c"	
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
     if(!present("servant 3"))
       new(ELFMOB"servant.c")->move(this_object());
}
