#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("The desert never seems to end, all sense of direction seems to disappear in the never ending dunes. Some scattered bones can be seen half buried in a dune close by. Vultures can be seen circling overhead.");
		
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			
			
			"southwest"		: ROOMS "muabark065.c",
			"southeast"		: ROOMS "muabark071.c",
			"north"			: ROOMS "muabark067.c",
			"east"			: ROOMS "muabark070.c",
			"west"			: ROOMS "md-skeleton.c",

		]));
}

void reset() {
   ::reset();

//if (children(MOB"md-nomad.c")==({})||
//    sizeof(children(MOB"md-nomad.c"))<7)
//     new(MOB "md-nomad.c")->move(this_object());

//if (!present("scorpion", this_object()))
//    new(MOB"md-scorpion.c")->move(this_object());
//if (!present("snake", this_object()))
//    new(MOB"md-snake.c")->move(this_object());
if (!present("scorpion", this_object()))
    new(MOB"md-scorpion.c")->move(this_object());
if (!present("scorpion 2", this_object()))
    new(MOB"md-scorpion.c")->move(this_object());




}
