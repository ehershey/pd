#include <std.h>
#include <durst.h>

inherit ROOM;

void create() 
{
	::create();
		set_name("ice cavern");
		set_short("A glimmering ice cavern");
		set_long("This looks to be a giant cavern made of ice. Light dances off the walls in all directions, and rainbows of light stretch everywhere. A small pool of liquid water is near the center of the cavern. The air is crisp and stale, this cavern must not have been exposed to the outside atmosphere for a long time.");
		set_properties(([
			"light"		: 3,
			"night light"	: 1,
			"polar"         : 1,
			"indoors"       : 1,
			"no teleport"   : 1,
		]));
		
		
		set_exits(([
			
			"west"			: ROOMS "muabark064.c",
			
			
		]));
}

void reset() {
   ::reset();



}
