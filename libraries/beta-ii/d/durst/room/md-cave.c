#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("deep cave");
		set_short("A dark cave");
		set_long("This looks to be a long dark cave, very little can be seen. The air is thick, and there seems to be some sort of gas in the air, the gas makes it difficult to breathe. This cave probably hasn't been exposed to the outside air in a long time. The walls of the cave sparkle lightly. The source of the sparkle can't be determined.");
		set_properties(([
			"light"		: 1,
			"night light"	: 1,
			"indoors"         : 1,
			"no teleport"	: 1,
		]));
		
		
		set_exits(([
			
			"north"			: ROOMS "muabark037.c",
			
			
		]));
}

void reset() {
   ::reset();



}
