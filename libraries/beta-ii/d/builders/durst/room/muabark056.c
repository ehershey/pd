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
			
			"southeast"		: ROOMS "muabark044.c",
			"southwest"		: ROOMS "muabark058.c",
			"north"		: ROOMS "muabark055.c",
			"west"		: ROOMS "muabark059.c",
			
		]));
}

void reset() {
   ::reset();

//if (children(MOB"md-nomad.c")==({})||
//    sizeof(children(MOB"md-nomad.c"))<7)
//     new(MOB "md-nomad.c")->move(this_object());

if (!present("scorpion", this_object()))
    new(MOB"md-scorpion.c")->move(this_object());
if (!present("snake", this_object()))
    new(MOB"md-snake.c")->move(this_object());
if (!present("lizard", this_object()))
    new(MOB"md-lizard.c")->move(this_object());




}
