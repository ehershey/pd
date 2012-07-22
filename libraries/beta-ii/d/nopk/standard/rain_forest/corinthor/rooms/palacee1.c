//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The palace is absolutely amazing. The entire palce is built not out of cut wood, but rather of living trees. Here, the main entrance splits off to the east, leading the the guest's residencies. The sun can be seen through the leaves above.");
     set_night_long("The palace is absolutely amazing. The entire place is built not of wood, but rahter out of living trees. here, the main entrance splits off to the east towards the guest's residencies. The stars and moons can be seen high above through the leaves.");
     set_exits(([
                "northeast"     : ELFROOM"palaceee1.c",
                "west"          : ELFROOM"palacem1.c",
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("royalguard"))
       new(ELFMOB"royalguard.c")->move(this_object());
}
