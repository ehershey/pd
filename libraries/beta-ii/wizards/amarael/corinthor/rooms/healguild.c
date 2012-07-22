//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Healer's Guild");
     set_long("This is the Corinthian Healer's Guild. Nearly all elves come here to learn basic healing practices, and quite a few even stay on to complete magical and herbal healing courses. A few elves pass by, looking for general supplies they need. One elf stands behind a counter with a sign beside him.");
     set_exits(([
                "east"		: ELFROOM"sun6.c"
                ]));
     set_items(([
		"sign" : "It has writing on it that you could read."
		]));
}

void reset() {
   ::reset();
     if(!present("mori'nen"))
       new(ELFMOB"healer.c")->move(this_object());
}
