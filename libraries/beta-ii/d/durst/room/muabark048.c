#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("Sand dunes as far as the eye can see, only the sky gives something else to look at. Not one plant can be seen anywhere, the desert looks to be completely dead. The winds kick up enough sand to make it difficult to see very far.");
		
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			
			"north"		: ROOMS "muabark052.c",
			"south"		: ROOMS "muabark047.c",
			"southwest"		: ROOMS "muabark044.c",
			"northeast"		: ROOMS "muabark049.c",
			
		]));
}

void reset() {
   ::reset();

if (children(MOB"md-nomad.c")==({})||
    sizeof(children(MOB"md-nomad.c"))<10)
     new(MOB "md-nomad.c")->move(this_object());
if (!present("lizard", this_object()))
     new(MOB"md-lizard.c")->move(this_object());
if (!present("lizard 2", this_object()))
     new(MOB"md-lizard.c")->move(this_object());
if (!present("lizard 3", this_object()))
     new(MOB"md-lizard.c")->move(this_object());



}
