#include <std.h>
#include <simaril.h>
#include <daemons.h>

inherit DOCKS;

void create()
{
    ::create();
        set_name("simaril pier");
        set_short("Simaril Pier");
        set_long("This is one of the piers of Silmaril. "
			"Large crates line the sides of the pier, they are stacked poorly. "
			"Near the crates are dozens of barrels stacked more neatly. "
			"The sea surrounds the pier, meeting the horizon to the north. "
			"Many boats large and small line the pier. "
			"A large city can be seen not too far to the South.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "town"        : 1,
        ]) );
        set_items(([
    	"piers"     :   "Several large wooden piers jut out into the sea from the land to the south.",
    	"pier"      :   "A large wooden structure, it meets with land to the south. Many large wooden pillars stretch into the air, stabilizing the pier, and are used by ships to secure them to the structure.",
        "crates"    :   "Many large wooden boxes that have been stacked rather poorly all across the pier, most of them have strange symbols written on them.",	
        "crate"     :   "A large wooden box with some straw hanging out of the top of it. it looks like the top is loose and could be opened with a little effort.",
        "barrels"   :   "A large assortment of wooden barrels, many contain liquor no doubt. Some probably carry fish from the previous days catch.",
        "barrel"    :   "A large wooden barrel with a picture of a flame on it, perhaps this barrel contains the famous flamethrower drink!",
        "sea"       :   "The endless sea meets the horizon far to the north, its waves slam into the pier.",
        "boats"     :   "A large variety of boats, some as small as dinghies, and some as large as warships.",
        "city"      :   "The port town of Simaril, if it can be found in the world, it is probably sold here. Traders come from all around the world to try and sell rare and expensive items.",
     	({"symbol", "symbols"})	:	"It looks to be the image of a lamp with some strange glyphs above the lamp.",
     	"warship"	:	"A large vessel bristling with cannons. There doesn't appear to be any way to get on the ship.",
	    ]));
	    set_listen("default", "The sound of dock workers moving crates and barrels comes from all directions.");
	    set_smell("default", "Sea salt fills the air, drowning out all other smells.");
	    set_smell("barrels", "There must be some liquors being held in these.");
		set_exits(([
			"south"		: ROOMS"simaril002.c",
        ]));
            set_letter("E");
}
 
void reset() {
   ::reset();
	if (!present("nyeng", this_object()))
    	new(MOB"nyeng.c")->move(this_object());
}
      
void init() {
	::init();
		add_action("searching", "search");
}

int searching(string str)
{
	if(!str) return notify_fail("Search what?\n");
	
	if(str == "crates")
	{ 
		message("info",
			"Search which crate?", this_player());
		return 1;
	}
	if(str == "crate")
	{
		message("info", 
			"As you try and open one of the crates, a dock hand comes over and slams the crate shut!"
			, this_player());
		return 1;	
	}	
	if(str == "barrels")
	{
		message("info", "Search which barrel?", this_player());
		return 1;
	}
	if(str == "barrel")
	{
		message("info",	"There doesn't seem to be a way into the barrel."
			, this_player());
			return 1;
	}
}
