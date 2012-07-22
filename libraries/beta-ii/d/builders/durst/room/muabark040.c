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
			"north"			: ROOMS "muabark043.c",
			"southeast"		: ROOMS "muabark041.c",
			"west"			: ROOMS "muabark039.c",
			"northeast"			: ROOMS "muabark045.c",
		]));
}


void reset() {
   ::reset();


if (!present("snake", this_object()))
     new(MOB"md-snake.c")->move(this_object());
if (!present("snake 2", this_object()))
     new(MOB"md-snake.c")->move(this_object());
if (!present("lizard", this_object()))
     new(MOB"md-lizard.c")->move(this_object());


}
