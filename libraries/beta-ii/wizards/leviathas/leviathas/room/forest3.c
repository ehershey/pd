#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^GREEN%^Trees bend in different directions, some tangling up with each other but all conforming "
          "to the path.  %^BOLD%^Grass grows tall, suggesting that no one has walked through here in a long time. "
          "A couple of rocks sit on the ground but the area is otherwise plain.");
   
    set_night_long("%^GREEN%^Trees bend in different directions, some tangling up with each other but all conforming "
          "to the path.  %^BOLD%^Grass grows tall, suggesting that no one has walked through here in a long time. "
          "A couple of rocks sit on the ground but the area is otherwise plain.");
    
    set_items(([
        "trees" : "Could they have been planted to create this path?",
        "formation" : "It is to the southeast.",          
        
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "forest2.c",
        "east" : ROOMS "forest4.c",
                
                
    ]));

}


