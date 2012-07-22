//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Mage's Guild");
     set_long("This is the Corinthian Mages guild. Many elves spend some of their spare time here learning various magical disciplines. A few move around the place looking for bits and pieces they need to buy for their spells. Another elf stands behind a counter with a sign sitting next to him.");
     set_exits(([
                "east"		: ELFROOM"moons1.c"
                ]));
     set_items(([
		"sign" : "It has writing on it that you could read."
		]));
}

void reset() {
   ::reset();
     if(!present("stoner"))
       new(ELFMOB"stoner.c")->move(this_object());
}
