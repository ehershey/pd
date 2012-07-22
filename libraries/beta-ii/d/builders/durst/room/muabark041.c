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
			"north"			: ROOMS "muabark042.c",
			"northwest"		: ROOMS "muabark040.c",
			"east"			: ROOMS "muabark056.c",
			
		]));
}
