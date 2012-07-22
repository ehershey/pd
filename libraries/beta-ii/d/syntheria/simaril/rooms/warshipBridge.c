#include <std.h>
#include <simaril.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("warship bridge");
        set_short("Warship Bridge");
        set_long("In the center of the bridge is the large wheel. "
        		 "To the North is the bow of the vessel. "
        		 "Dozens of crates lay all over the deck. "
        		 "From the bridge the open sea can be seen everywhere. "
		);  
        set_properties( ([
        "light"       : 2,
        "night light" : 0,
        "town"        : 1,
        ]) );
        set_items(([
    		"wheel"		:	"A large wooden wheel used to steer the vessel.",
    		"bow"		:	"The front end of the warship.",
    		"crates"	:	"Large crates used for shipping. There are many different kinds of them.",
    		"sea"       :   "The endless sea meets the horizon far to the north, the waves slam into the ship.",
	    ]));
	    set_listen("default", "The bridge is quiet.");
	    set_smell("default", "Sea salt fills the air, drowning out all other smells.");
		set_exits(([
			"deck"		: ROOMS"warship01.c",
        ]));
}
 
void reset() {
   ::reset();
	if(!present("thyas", this_object()))
		new(MOB"thyas")->move(this_object());

}
      


void init() {
	::init();
		add_action("turn_wheel", "turn");
} 

int turn_wheel(string str)
{
	string dir;
	int r;
	if(!str) return notify_fail("Turn what?\n");
	if(str != "wheel") return notify_fail("You can not turn that!\n");
	r = random(2);
	if(r == 0)
		dir = "right";
	else
		dir = "left";
	
	message("player", "You grab the wheel, and turn it to the "+dir+"!", this_player());
	message("room", this_player()->query_cap_name()+
			" grabs the wheel of the boat and turns it to the "+dir+"!",
			environment(this_player()), this_player());
	this_player()->add_sp(-random(5));
	 
	
	return 1;
}
