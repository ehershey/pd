//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("This hallway connects all other passages from the throne room and main hallway to the guest quarters. The area is a main walkway for guests bustling around the palace as they concduct official business with the king and council. It is especially busy here during the day.");
     set_night_long("This hallway connects all other passages from the throne room and main hallway to the guest quarters. The area is a main walkway for guests bustling in and out of the throne room on official business with the king and council. It is no less busy at night with cleaning to be done.");
     set_exits(([
                "north"         : ELFROOM"palacee4.c",
                "southeast"     : ELFROOM"palaceee2.c",
                "south"         : ELFROOM"palacee2.c" 
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
