#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("Sand dunes as far as the eye can see, only the sky gives something else to look at. Not one plant can be seen anywhere, the desert looks to be completly dead. The winds kick up enough sand to make it difficult to see very far.");
		
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			"north"		: ROOMS "muabark005.c",
			"south"		: ROOMS "muabark004.c",
			"west"		: ROOMS "muabark002.c"
		]));
}

void reset() {
   ::reset();


if (!present("lizard", this_object()))
     new(MOB"md-lizard.c")->move(this_object());

}
