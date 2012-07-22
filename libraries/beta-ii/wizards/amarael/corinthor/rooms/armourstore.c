//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthian Armour Storage");
     set_long("This is the storage room for Corinthian Armours");
     set_exits(([
                "out"		: ELFROOM"armourshop.c"
                ]));
}

void reset() {
   ::reset();
     if(!present("chainmail"))
       new(ELFARMOUR"elvenchain.c")->move(this_object());
}
