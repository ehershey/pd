#include <lost.h>
#include <mjungle.h>
#include <std.h>
inherit ROOM;

void create() {
  ::create();
	set_short("The lost jungles of Merkkirri");
	set_long("This place is filled with large geysers, many with bubbling hot water pouring out of them. Steam pours into the air, making the area around the geysers humid and hot. The ground is muddy and difficult to walk on, the water makes this place a graveyard for any small animals that come here. Small bones can be seen sticking out of the ground.");
	set_property("forest",1);
	set_items(([
		"jungle" : "The jungle seems to have never been touched by evolution.  It's as if you are stepping millions of years into the past...",
		({"leaves", "trees", "plants"}): "The plantlife here is large and yet very simple in design.  It's as if the world evolved yet this place stood still.", 
		"geysers"	:	"Large holes in the ground with hot water bubbeling out of them."
	]));
	set_properties((["light" : 2, "night light" : 1,]));
	set_exits(([
		"northwest": ROOMS "lost8.c",
	]));
	set_heart_beat(1);
}

void reset() {
 ::reset();
}

void heart_beat()
{
	object *victims=({});
	int i;
    if (random(100) > 85)
    {
		if (random(100) > 75)
		{
			message("room", "A geyser explodes under your feet! Throwing you into the air!", this_object());	
			victims = all_inventory(this_object());
			for(i = 0; i < sizeof(victims); i++)
			{
				if(victims[i]->is_living())
				{
					victims[i]->damage(10 + random(20));
					victims[i]->move( MJUNGLE "mjungle18.c",);	
					victims[i]->force_me("look");						
				}
			}
		}
		else
		{
			message("room", "A small geyser off in the distance explodes, throwing water into the air!", this_object());	
		}
	}
}
