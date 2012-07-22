#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("Tower of the Deathless");
    set_day_long("The tower of the vampires, the deathless ones, is "
                 "one of the most beautiful places that exists.  It's "
                 "beauty is seductive and quite remarkable. "
                 "There are amazingly crafted stone stairs that lead "
                 "up into a room with a dim, %^MAGENTA%^magenta %^RESET%^"
                 "light shining from it.  The wall to your left has "
                 "a painting on it of Cain, while the wall to your right "
                 "is blank.  There is a farily long hall here to the "
                 "north ending in those beautiful stairs.  There is a "
                 "carpet of flesh that squeeks every time you take a "
                 "step on it. There is an eye ball in the southwest "
                 "corner of the hall. ");
   
    set_night_long("The tower of the vampires, the deathless ones, is "
                 "one of the most beautiful places that exists.  It's "
                 "beauty is seductive and quite remarkable. "
                 "There are amazingly crafted stone stairs that lead "
                 "up into a room with a dim, %^MAGENTA%^magenta %^RESET%^"
                 "light shining from it.  The wall to your left has "
                 "a painting on it of Cain, while the wall to your right "
                 "is blank.  There is a farily long hall here to the "
                 "north ending in those beautiful stairs.  There is a "
                 "carpet of flesh that squeeks every time you take a "
                 "step on it. There is an eye ball in the southwest "
                 "corner of the hall. ");
    
    set_items(([
	"stone" : "The stone looks quite divine.",
	"stairs" : "They are made out of that interesting stone.",
        "light" : "The light fills your body with a seductive pleasure, "
               "while a shadow seems to creep up on you...",
        "wall" : "Left, or right wall?",
        "left wall" : "It is a painting of Cain, the first to murder "
               "and eventually become the first vampire. There is "
               "something written on the base of the painting in glowing, "
               "%^RED%^red%^RESET%^ letters.",
        "right wall" : "The canvas on this painting is white, but "
               "otherwise empty.",
        "hall" : "As you take a better look at the whole hall, a huge "
               "weight falls upon you and your vision blurs.",
        "carpet" : "It was made of flesh.",
        "eye ball" : "The eye turns and looks at you!",
                  
        	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"down" : ROOMS "vtower1.c",
        "stairs" : ROOMS "vtower3.c",
    ]));
}
