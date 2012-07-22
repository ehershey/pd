//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthian Weapon Storage");
     set_long("This is the storage room for Corinthian Weapons");
     set_exits(([
                "out"		: ELFROOM"weaponshop.c"
                ]));
}

void reset() {
   ::reset();
     if(!present("longsword"))
       new(ELFWEAPON"elfsword.c")->move(this_object());
}
