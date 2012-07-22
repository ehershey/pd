//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 2, "indoors" : 1 ]));
     set_short("Corinthor Home");
     set_long("This room has the look of a kitchen, though a slightly odd one. There is an oven, but no room for a fire beneath it, nor any fireplace in the room. Just the benches and some cutlery around. A door in the eastern wall of this room leads back out to the living area.");
     set_exits(([
                "east"		: ELFROOM"sunhome1.c"
                ]));
     set_items(([
		"oven" : "It's just a hole in the wall with a door to cover it. Nothing indicating any kind of heat source.",
		"cutlery" : "Cutlery",
		"benches" : "The benches are flat, and made of wood like everything in Corinthor. Some cutlery lies at the end."
		]));
}

void reset() {
   ::reset();
     if(!present("lord"))
       new(ELFMOB"sunhlord.c")->move(this_object());
}
