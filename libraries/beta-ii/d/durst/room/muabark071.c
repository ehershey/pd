#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("A large cyclone of sand makes navigation very difficult. The air is as thick as the sand below, breathing seems impossible. Death seems certain in this endless desert.");
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			"north"			: ROOMS "muabark070.c",
			"northwest"		: ROOMS "muabark066.c",
			"west"			: ROOMS "muabark072.c",
			"southeast"		: ROOMS "muabark054.c",
		]));
}

void reset() {
   ::reset();

//if (children(MOB"md-nomad.c")==({})||
//     sizeof(children(MOB"md-nomad.c"))<7)
//     new(MOB "md-nomad.c")->move(this_object());
//if (!present("snake", this_object()))
//     new(MOB"md-snake.c")->move(this_object());
if (!present("scorpion", this_object()))
     new(MOB"md-scorpion.c")->move(this_object());


}
