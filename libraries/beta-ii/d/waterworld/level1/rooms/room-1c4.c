#include <std.h>
#include <waterworld.h>

inherit ROOM;

void create()   {
      ::create();
       set_properties((["water":1,"light":3,"night light":3]));
       set_listen("default","You hear the old dock squeaking as it moves on its pilings.");
       set_long("A small dock is anchored to some pilings here."
              " There are many spots where boats can be tethered to it."
              " The water appears almost at rest.");
       add_invis_exit("climb ladder");
       set_exits(([
                 "east":ROOMS1"room-1d4.c",
                 "west":ROOMS1"room-1b4.c",
                 "north":ROOMS1"room-1c3.c",
                 "south":ROOMS1"room-1c5.c",
                     ]));
       set_items(([
                   "pilings":"They are long poles of timber that extend to the bay floor.",
                    "dock":"A ladder is secured to the side of the dock.",
                    "ladder":"Seems strong enough to climb up."
       ]));
       new(PEARLS"black_clam.c")->move(this_object());
}

// Mob regeneration
void reset() {
         ::reset();
          
	MOB1"selection_lvl1.c"->execute_selection_lvl1(random(7),this_object());
}
                

void init() {
  ::init(); 
  add_action("secret", "climb");
}
                 
                 
int secret(string str)
{
	if(!str) return notify_fail("Climb what?\n");
	if(str != "ladder") return notify_fail("That is not in sight.\n");
	
	message("player", "You climb up the ladder.\n", this_player());
	message("room", this_player()->query_cap_name()+ " climbs up a ladder.\n", environment(this_player()), this_player());
	this_player()->move(ROOMS1"secret-2a.c");
	this_player()->force_me("look");
        message("room", this_player()->query_cap_name()+" climbs onto the dock using the ladder.",environment(this_player()),this_player());
        return 1;
}
