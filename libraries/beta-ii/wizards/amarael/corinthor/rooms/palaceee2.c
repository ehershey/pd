//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("This part of the palace is reserved for noble guests of the royal court, to the northeast is a guest room for this purpose. There is a bit of activity here, with a few servants quickly shuffling in and out with food and drinks for the nobles. The corridor turns to the northwest leading towards the main hall and throne room.");
     set_night_long("This part of the palace is reserved for noble guests of the royal court, to the northeast is a guest room for this purpose. Activity here is minimal at night, with the nobles being asleep. The corridor curves around to the northwest leading towards the main hall and the throne room. The stars shine overhead.");
     set_exits(([
                "northwest"     : ELFROOM"palacee3.c",
                "south"         : ELFROOM"palaceee1.c",
                "northeast"     : ELFROOM"guest2.c"
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("royalguard"))
       new(ELFMOB"royalguard.c")->move(this_object());
}
