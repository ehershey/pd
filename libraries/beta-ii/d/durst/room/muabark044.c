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
			
			"north"		: ROOMS "muabark057.c",
			"south"		: ROOMS "muabark045.c",
			"northwest"		: ROOMS "muabark056.c",
			"northeast"		: ROOMS "muabark048.c",
			"southwest"		: ROOMS "muabark043.c",
			
		]));
}
