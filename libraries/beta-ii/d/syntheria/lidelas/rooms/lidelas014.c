#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("feng avenue");
        set_short("Feng avenue");
        set_long("Feng avenue bisects Lidelas, splitting the town into the north and south ends. Feng avenue runs from the far west end of town, to the far east side of town. The avenue is made of very fine cobble stone, each stone looks almost new. Many large buildings line the street, the common theme between them all is that every one of them has ornate sculptures of gargoyles at points all over the buildings. All of the gargoyles seem to have been made to face the street, so that they may look onto anyone who passes by. Every building has many arched windows, above every window is a sharp point that eventually leads to a sharp tower. To the south is a tall tower, with similar windows as the other buildings in the town. On the very top of the tower is a large statue, but it is to high up to see what it is. There doesn't seem to be any entrance to the tower, the only that can be seen on the tower is an archway at the very front, but behind it the archway is just a wall of the tower.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"gargoyles"    :   "They are not very large, and seem to be carved into the building.",
    	"tower"        :   "A large tower that reaches into the sky, a very soft glow radiates from it.",
    	"archway"      :   "A strange archway that is built into the north wall of the tower, but it doesn't lead to anything."
	    ]));
	    set_listen("default", "The sound of carts moving on the stone steets can be heard in all directions.");
	    set_smell("default", "The odor of horse manure fills the air.");
	    set_exits(([
			"east"       : ROOMS "lidelas016.c",
			"west"       : ROOMS "lidelas013.c",
			"archway"    : ROOMS "lidelas015.c"    
        ]));
        add_invis_exit("archway");
        add_pre_exit_function("archway", "go_archway");
}

int go_archway() {
  if(!this_player()->is_player()) return 0;
  return 1;
}


