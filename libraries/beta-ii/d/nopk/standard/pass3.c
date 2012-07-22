#include <std.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    ::create();
   set_property("mountain",1);
    set_property("light", 1);
    set_property("no castle", 1);
    set("short", "Mountain pass on the desert face");
    set("long",
        "You are just west of the highest point on this path through the "
        "Daroq Mountains.  South you can see were the mountains look "
        "friendlier, where they are known as the Destiny Mountains.");
    set_items(
	(["point" : "From here it looks like you can see the entire world.",
	  "pass" : "It goes down into the Qajip Desert.",
	  "mountains" : "A huge mountain range separating the fertile "
	    "lands of the east from the desert.",
	  "valley" : "A huge forested valley.",
	  "desert" : "The Qajip Desert where many travellers have "
	    "lost their way and not been found.",
	  "mountain" : "It is one of the lower ones, guarding the pass."]) );
      set_exits( 
		(["east" : ROOMS "pass2"]) );
}

void reset() {
  ::reset();
    if(!present("balrog")) 
      new(MOB "balrog")->move(this_object());
}

