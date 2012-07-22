//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("This is one of the seconday hallways leading to and from the throne room of the palace. During the day many servants are bustling here and there delivering food and drinks to those in audience in the throne room.");
     set_night_long("This is one of the secondary hallways leading to and from the throne room. There are alcoves nearby for guards to stand watch. There are a few servants bustling back and forth as the clean the place up ready for the next day.");
     set_exits(([
                "northeast"     : ELFROOM"throne.c",
                "south"         : ELFROOM"palacew3.c" 
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
