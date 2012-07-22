#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("The desert never seems to end, all sense of direction seems to disappear in the never ending dunes. Some scattered bones can be seen half buried in a dune close by. Vultures can be seen circling overhead.");
		set_items(([
		    "bones"  : "Some old bleached bones",
            "vultures"      : "They circle waiting for a meal"
		    ]));
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			"north"			: ROOMS "muabark010.c",
			
					
			
		]));
}

void reset() {
   ::reset(); 
if (children(MOB"md-nomad.c")==({})||
    sizeof(children(MOB"md-nomad.c"))<10)
     new(MOB "md-nomad.c")->move(this_object());
if (!present("lizard", this_object()))
     new(MOB"md-lizard.c")->move(this_object());
if (!present("snake", this_object()))
     new(MOB"md-snake.c")->move(this_object());

}
