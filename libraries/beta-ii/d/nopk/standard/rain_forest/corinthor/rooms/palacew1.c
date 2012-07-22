//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Palace");
     set_day_long("The palace is absolutely amazing. The entire place is built not of cut wood, but of living trees. Here the main entrance has split off to the west, leading to the servants quarters. The sun can be seen through the leaves above.");
     set_night_long("The palace is absolutely amazing. The entire place is built not of cut wood, but of living trees. Here the main entrance has split off to the west, leading to the servants quarters. The stars can be seen through the leaves above.");
     set_exits(([
                "northwest"     : ELFROOM"palaceww1.c",
                "east"          : ELFROOM"palacem1.c",
                ]));
     set_items(([
        ]));
}

void reset() {
   ::reset();
     if(!present("royalguard"))
       new(ELFMOB"royalguard.c")->move(this_object());
}
