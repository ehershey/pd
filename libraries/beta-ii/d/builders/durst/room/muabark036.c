#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("desert");
		set_short("The MuaBark desert");
		set_long("This section of the desert is very flat, it allows the wind to achieve new speeds. Small plants can be seen being blown around in the wind, there must be some life somewhere in this desert. Each step that is taken is quickly erased by the desert winds.");
		
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"dessert"     	: 1
		]));
		
		set_listen("default", "The deafening sound of the powerful desert winds drowns out all other sounds");
		set_exits(([
			"east"			: ROOMS "muabark037.c",
			"west"		: ROOMS "muabark026.c",
			
		]));
}

void reset() {
   ::reset();


if (!present("lizard", this_object()))
     new(MOB"md-lizard.c")->move(this_object());

if (!present("lizard 2", this_object()))
     new(MOB"md-lizard.c")->move(this_object());


}
