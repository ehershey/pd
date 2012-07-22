//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("This hallway connects all other passages from the throne room and main hallway to the servant's quarters. The area is a main thouroughfare for servants bustling around the palace delivering food and drinks not only to the king and council, but also to any of the noble guests. It is especially busy during the day.");
     set_night_long("This hallway connects all other passages from the throne room and main hallway to the servant's quarters. The area is a main thouroughfare for servants bustling in and out of the throne room carrying food and drinks for the king and council. It is no less busy at night with cleaning to be done.");
     set_exits(([
                "north"         : ELFROOM"palacew4.c",
                "southwest"	: ELFROOM"palaceww2.c",
                "south"         : ELFROOM"palacew2.c" 
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("royalguard"))
       new(ELFMOB"royalguard.c")->move(this_object());
     if(!present("servant"))
       new(ELFMOB"servant.c")->move(this_object());
}
