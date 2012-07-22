#include <std.h>
#include <hermes.h>
inherit ROOM;
void create()
{
	::create();
	set_properties
	(
	        (["light" : 3, "night light" : 2, "city" : 1])
	);
	set_short("Road out of Lodos.");
	set_smell("default", "The frest aroma of pine trees fills the air.");
    set_listen("default", "The noise of the city, rapidly fading.");
	set_day_long
	(
	        "The noise of Lodos starts to fade away as you "
	        "head outside the city limits.  Gradually, the "
	        "stone and mortar of the big city gives way to "
	        "a well worn trail.  The buildings, although "
	        "still visible, have started to fade away, "
	        "to be replaced by trees. A sign sticks in "
	        "the road to one side. Not obscured by any growth."
	);
	set_night_long
	(
	        "The path is at first easily made out thanks to the "
	        "light coming from the city. But as the city  "
	        "starts to fade, gradually replaced by the forest, the path "
	        "becomes less clear. A sign sticks in "
	        "the road to one side. Not obscured by any growth."
	);
	set_items
	(
	        ([
	                "sign" : "Oddly enough, there is ambient light that adjusts itself according to the time so that it can be read anytime.",
	                ({"lodos", "Lodos"}) : "The city of Lodos streches out to the west. The citizens going about their tasks in oblivion to the hero that just walked through their midst.",
	                ({"trail", "path"}) : "A well worn trail, leading to the east through a vast forest."
	        ])
	);
	set_exits
	(([
		"path" : ROOMS "path",
		"west" : "/d/lodos/etown7.c"
	]));
}
void reset() 
{
	::reset();
	if(!present("sign")) 
	new(ITEMS"lodsign")->move(this_object());
}
