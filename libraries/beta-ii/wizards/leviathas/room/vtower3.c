#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("Tower of the Deathless");
    set_day_long("%^MAGENTA%^The light here goes all the way down a long "
                 "hall.  Doors line the sides of the hall and have been "
                 "placed here for the vampires.  Cain's room is at the end "
                 "of the hall and is decorated by a %^YELLOW%^golden door%^RESET%^%^MAGENTA%^ with "
                 "different designs on it. The floor is made of that same flesh carpet, the walls "
                 "are black, tinted by the magenta light and corner of the hall. ");
   
    set_night_long("%^MAGENTA%^The light here goes all the way down a long "
                 "hall.  Doors line the sides of the hall and have been "
                 "placed here for the vampires.  Cain's room is at the end "
                 "of the hall and is decorated by a %^YELLOW%^golden door%^RESET%^%^MAGENTA%^ with "
                 "different designs on it. The floor is made of that same flesh carpet, the walls "
                 "are black, tinted by the magenta light and corner of the hall. ");
    
    set_items(([
	"light" : "It's pretty dim..",
	"doors" : "The doors all look fit for a god.",
        "golden door" : "This leads to Cain's room.",
        "designs" : "Wow, look at em!",
        "floor" : "EWWWW!",
                          
        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"north" : ROOMS "vtower4.c",
        "stairs" : ROOMS "vtower2.c",
        "east" : ROOMS "blank1.c",
        "west" : ROOMS "blank2.c",

    ]));
}
