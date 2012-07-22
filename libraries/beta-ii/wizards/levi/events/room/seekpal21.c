#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Divine Throne Room");
    set_long("This is the Avatar's divine throne room.  The floor is made of diamond tiles and "
	"the walls made of long beaded strings that flap gently in the wind.  This room must be partially outdoors. "
	" A massive throne takes up the northern area of the room, a silver throne adorned with many jewels.  To the "
	"east and west, two smaller thrones marked 'fire' and 'earth' have been placed.  They are also quite "
	"beautiful but obviously created to look pale in comparison with the larger.  A staircase leads down.");
    
    set_items(([
          "throne" : "Which one?",
	  "large throne" : "The throne of the Avatar.  It is over-jeweled and probably the most valuable chair in the world.",
	  "beads" : "The walls are composed of strings of beads.",
	  "staircase" : "The staircase must have taken months to create.  The detail is magnificient, somehow even beads of water are suspended in the air.",
	  "fire throne" : "The fire throne is actually burning.  It is composed of amber and gold.  Quite beautiful but nothing compared to the large one.",
	  "earth throne" : "Tiger's Eye adorns the earth throne with at least ten thousand tiny pieces.  Gold has 'mortared' between the bits.  It is obviously inferior to the large throne.",
	  "tiles" : "The tiles are actually large diamonds.",
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "down" : ROOMS "seekpal20.c",
			
        
       ]));
       
}


