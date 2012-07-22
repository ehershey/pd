#include <std.h>
#include <simaril.h>

inherit ROOM;

int op_chest(string);
int found = 0;
void create()
{
    ::create();
        set_name("captain's cabin");
        set_short("Captain's Cabin");
        set_long("The cabin is rather large compared to the other areas of the ship. "
        		 "A large wooden table sits in the center of the room, several chairs surround it. "
        		 "On the South wall a large bed sits on the floor. "
        		 "A large wooden chest sits on the floor near the bed. "
        		 "The East wall holds a large dresser for the captain's clothes. "
        		 "A large wooden clock is mounted on the West wall. "
        		 "Behind the bed is a large series of windows. "
		);  
        set_properties( ([
        "light"       : 1,
        "night light" : 1,
        "indoors"     : 1,
        ]) );
        set_items(([
		"table"		:	"A solid oak table, made by hand. The table is covered with a fine silk sheet. Several candles stand near the center of the table. Four plates line the table.",
		"sheet"		:	"An expensive looking royal %^BOLD%^%^BLUE%^blue%^RESET%^ silk table cloth.",
		"candles"	:	"Large candles that sit in the middle of the table. All are lit, and glow softly.",
		"plates"	:	"Fine china of the captain.",
		"chairs"	:	"Solid oak chairs that match the table perfectly. They have cloth pads attatched to the seats.",
		"bed"		:	"A large bed adorned with expensive looking pillows and sheets.",
		"pillows"	:	"Large soft pillows covered with silk.",
		"sheets"	:	"Fine silk sheets, they match the pillows perfectly.",
		"chest"		:	"A large wooden chest with iron supports. It looks to be sealed shut with an iron lock.",
		"dresser"	:	"A large oak dresser with four drawers built in to it.",
		"drawers"	:	"Compartments built into the dresser, perhaps there is something inside one of them.",
		"clock"		:	"A large wooden wall clock, it looks hand crafted and old.",
		"windows"	:	"Large stained glass windows that look out the back end of the ship.",

	    ]));
	    set_listen("default", "The ticking of a clock can be heard coming from somewhere in the room.");
	    set_smell("default", "Burning candles fill the air with the smell of smoke.");
		set_exits(([
			"deck"		: ROOMS"warship01.c",
        ]));
        add_pre_exit_function("deck", "go_deck");
}
 
int go_deck()
{
	object tp;
	object mon;
	tp = this_player();
	if(!mon = present("chestin", this_object())) 
		return 1;
	if(!present("scope", tp))
		return 1;
	mon->force_me("say I'll not be letting ye leave here with my property! Now give me the telescope!");
	message("info", "Captain Chestin blocks your exit!", this_player());
	mon->force_me("wield sword");
	return 0;
			
}

void init() {
	::init();
		add_action("op_chest", "open");
		add_action("searching", "search");
		add_action("hit_comp", "hit");
} 

int hit_comp(string str)
{
	object mob;
	if(!str) return notify_fail("Hit what?\n");
	
	if(str != "compartment") return notify_fail("You can not hit that!\n");
	
	message("info", "You hit the compartment with your fist and it pops open!", this_player());
	if(found == 0)
	{
		message("info", "You find a small telescope in the compartment!", this_player());
		new(OBJ"telescope.c")->move(this_player());
		found = 1;	
		if(mob=present("chestin", this_object()))
		{
			message("target", "The captain gives you an menacing look.", this_player());
			message("room", "The captain gives "+this_player()->query_cap_name()+
				" a menacing look.", environment(this_player()), this_player());	
		}
	}
	else
	{
		message("info", "The compartment is empty!", this_player());	
	}
	return 1;
}

int searching(string str)
{
	if(!str) return notify_fail("Search what?\n");
	
	if(str == "dresser")
	{
		message("info", "You search the dresser and notice a small compartment near the bottem of the dresser.", this_player());	
	}
	if(str == "compartment")
	{
		message("info", "The compartment doesn't seem to have any handle on it. Perhaps there is a trick to opening it.", this_player());	
	}
	if(str == "drawers")
	{
		message("info", "As you go through the drawers, you don't find anything but the captain's clothes.",this_player());	
	}
	return 1;
}

int op_chest(string str)
{
	if(!str)
		return notify_fail("Open what?\n");
	if(str != "chest")
	{
		return notify_fail("You can not open that!\n");	
	}
	message("info", "You try and open the chest, but it is sealed with an iron lock.", this_player());
	message("room", this_player()->query_cap_name()+ " tries to open a large chest, but can't seem to open it.", environment(this_player()), this_player());	
	return 1;	
}

void reset() {
   ::reset();
   	if(!present("chestin", this_object()))
		new(MOB"chestin.c")->move(this_object());
	found = 0;
}
