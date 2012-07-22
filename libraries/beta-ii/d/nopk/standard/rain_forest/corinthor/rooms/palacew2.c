//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("Leading off from the main hallway, this place joins the servants quarters to the rest of the palace. Some of the trees forming hte corridors have an alcove, just large enough to fit a guard to stand and watch the area. Overhead the daytime sky can be seen through the leaves, with the sun shining down in all it's glory.");
     set_night_long("Leading off from the main hallway, this place joins the servants quarters to the rest of the palace. Some of the trees forming the corridors have an alcove, just large enough for a guard to stand and watch the area. Overhead the night sky can be seen through the leaves, with stars and moons shown in all their glory.");
     set_exits(([
                "northeast"     : ELFROOM"palacem4.c",
                "southeast"	: ELFROOM"palacem2.c",
		"north"		: ELFROOM"palacew3.c"	
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("royalguard"))
       new(ELFMOB"royalguard.c")->move(this_object());
     if(!present("royalguard 2"))
       new(ELFMOB"royalguard.c")->move(this_object());
}
