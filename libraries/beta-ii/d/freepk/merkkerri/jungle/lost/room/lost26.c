#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("Giant trees block out the sky with their giant leaves, only small patches of sky can be seen through the cover. The trees look to be very old, most likely the oldest life in the jungle. There are a few vines here hanging from the trees, they are thin and have some small leaves growing from them. Large mushroom patches dot the forest floor here, some are as big around as the trees.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		"vines"		: "Small thin vines, they look climbable."
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"southwest"	: ROOMS "lost25.c",
		"north"		: ROOMS "lost27.c",
	]));
}

void reset() {
 ::reset();
	if (!present("dinosaur", this_object()))
    	new(LOSTMOB"ankylosaurus.c")->move(this_object());
	if (!present("dinosaur 2", this_object()))
    	new(LOSTMOB"ankylosaurus.c")->move(this_object());
}

void init()
{
    ::init();
        add_action("climb_up", "climb");
}

int climb_up(string str)
{
	if (str == "vines")
	{
		message("tp", "You climb up the vines.", this_player());
		message("others", this_player()->query_cap_name()+" climbs up some vines.", environment(this_player()), this_player());	
		this_player()->move(ROOMS "stand.c");
		this_player()->force_me("look");
	}
	else
	{
		message("tp", "Why would you want to climb that?", this_player());
		message("others", this_player()->query_cap_name()+" makes a climbing motion, how strange.", environment(this_player()), this_player());
	}	
	return 1;
}
