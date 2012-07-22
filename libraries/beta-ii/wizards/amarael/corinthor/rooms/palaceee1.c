//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("This part of the palace is reserved for noble guests of the royal court, to the northeast is a room for this purpose. There is a bit of activity here, with a few servants quickly shuffling in and out with food and drinks for the nobles. An alcove by the room's entrance allows a guard to stand watch.");
     set_night_long("This part of the palace is reserved for noble guests of the royal court, to the northeast is a room for thei purpose. Activity here is minimal at night, with the nobles being asleep. An alcove by the room's entrance allows a guard to watch out for the guests under the moonlight.");
     set_exits(([
                "north"         : ELFROOM"palaceee2.c",
                "southwest"     : ELFROOM"palacee1.c",
		"northeast"	: ELFROOM"guest1.c"
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("royalguard"))
       new(ELFMOB"royalguard.c")->move(this_object());
}
