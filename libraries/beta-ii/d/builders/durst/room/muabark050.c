#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("The MuaBark Desert stretches off in all directions. Large sand dunes make it impossible to see very far in any direction. A powerful wind kicks sand into the air, making it difficult to breath.");
		
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			
			"west"		: ROOMS "muabark049.c",
			"north"		: ROOMS "muabark054.c",
			"south"		: ROOMS "muabark051.c",
			
			
		]));
}

void reset() {
   ::reset();

//if (children(MOB"md-nomad.c")==({})||
//    sizeof(children(MOB"md-nomad.c"))<7)
//     new(MOB "md-nomad.c")->move(this_object());

//if (!present("scorpion", this_object()))
//    new(MOB"md-scorpion.c")->move(this_object());




}
