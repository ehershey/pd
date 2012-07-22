#include <std.h>
#include <simaril.h>

inherit ROOM;
int padlock = 0;
void create()
{
    ::create();
        set_name("simaril pier");
        set_short("Simaril Pier");
        set_long("This is one of the large piers of Simaril. "
        		 "Many different types of boats line the pier. "
        		 "Several large boxes sit off to one side of the pier. "
        		 "To the South is the city of Simaril. "
        		 "The sea surrounds the pier. "
        		 "One of the boats looks like it is carrying more cargo than it can handle."
		);  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "town"        : 1,
        ]) );
        set_items(([
    	"piers"     :   "Several large wooden piers jut out into the sea from the land to the south.",
    	"pier"      :   "A large wooden structure, it meets with land to the south. Many large wooden pillars stretch into the air, stabilizing the pier, and are used by ships to secure them to the structure.",
        "sea"       :   "The endless sea meets the horizon far to the north, its waves slam into the pier.",
        "boats"     :   "A large variety of boats, some as small as dinghies, and some as large as warships.",
        ({"city","simaril"})      :   "The port town of Simaril, if it can be found in the world, it is probably sold here. Traders come from all around the world to try and sell rare and expensive items.",
     	"boxes"		:	"Large boxes made of wood, they look like they are used for long term storage.",
     	"box"		:	"A large box made of wood, it looks like it is used for long term storage.",
     	"warship"	:	"A large vessel bristling with cannons. A long wooden plank connects the pier to the warship.",
     	"plank"		:	"A simple wooden board used to allow dock hands to move crates on to the ship.",
     	"door"		:	"A simple door on the north side of the box.",
	    ]));
	    set_listen("default", "Dock hands can be heard cursing all around.");
	    set_smell("default", "Sea salt fills the air, drowning out all other smells.");
		set_exits(([
			"north"		: ROOMS"simaril001.c",
			"plank"		: ROOMS"warship01.c",
                        "south"         : ROOMS"simaril003.c",
        ]));
		add_invis_exit("plank"); 
}
 
void reset() {
   ::reset();
   	if(!present("achray", this_object()))
   		new(MOB"achray.c")->move(this_object());
   
	if(padlock)
		remove_item("lock");
		remove_item("padlock");
	padlock = 0;
}
      
void init() {
	::init();
		add_action("searching", "search");
		add_action("op_door", "open");
}

int op_door(string str)
{
	if(!str)
		return notify_fail("Open what?\n");
	if(str != "door")
		return notify_fail("You can not open that!\n");
	if(padlock == 0)
	{
		message("info", "As you start to tug on the door, a dock hand comes over and puts his hand on the door. He pulls a padlock out of his overalls and locks the door.\nAfter giving you a dirty look, the dock hand walks off to the South.", this_player());	
		padlock = 1;
		add_item("padlock", "A large padlock made of iron. It has a large hole at the bottem where the key goes. It looks very old and is rusty.");
		add_item("lock", "A large padlock made of iron. It has a large hole at the bottem where the key goes. It looks very old and is rusty.");
	}
	else
	{
		message("info", "The door appears to be padlocked shut.", this_player());	
	}
	return 1;
}

int searching(string str)
{
	if(!str) return notify_fail("Search what?\n");
	if(str == "boxes")
	{
		message("info", "You do a quick look over of all the boxes and don't see anything strange.", this_player());
		return 1;	
	}	
	if(str == "box")
	{
		message("info", "As you look over one of the boxes, you notice a small door on the North side of the box.", this_player());	
		return 1;
	}
	if(str == "door")
	{
		if(padlock == 0)
		{
			message("nolock", "You see that the door is small, and could possibly be opened with enough force.", this_player());	
		}
		else
		{
			message("locked", "The door is small, but it appears to be padlocked shut.", this_player());
		}
		return 1;
	}	
}
