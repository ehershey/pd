#include <lost.h>
#include <mjungle.h>
#include <daemons.h>
#include <std.h>
inherit ROOM;

object mon;

void create() {
  ::create();
	set_short("Small tree stand");
	set_long("This looks to be some sort of small tree stand high up in the trees. This place is the first evidence that someone has been to this forest before. The stand looks to be very old, but still sturdy. It is made from wood not of this jungle, perhaps the people who made it are still around.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"down"		: ROOMS "lost26.c",
	]));
}

void reset() {
 ::reset();

	if ((EVENTS_D->query_month_name(time()) == "Virash" 
		|| EVENTS_D->query_month_name(time()) == "Qualtiar"
			|| EVENTS_D->query_month_name(time()) == "Tathsun") 
				&& query_night() == 1)
	{
		if (!present("hunter", this_object()))
		{
    		new(LOSTMOB"hunter.c")->move(this_object());
    		message("info", "A shadowy figure enters the tree stand.", this_object());
		}
	}
 	if (!query_night())
 	{
		if (mon = present("hunter", this_object()))
		{
    		mon->remove();
    		message("info", "The hunter leaves the stand, climbing down the vines.", this_object());
		}			
	}
}
