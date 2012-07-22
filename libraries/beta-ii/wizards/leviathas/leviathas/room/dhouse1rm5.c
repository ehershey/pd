#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("This would appear to be some sort of wash room.  A large, stone bowl full of hot water rests on top of a "
            "tiny pillar of similar material.  A circular mirror with incredible golden designs branching out of it sits "
            "above the bowl and two chairs sit on either side of it.  Another, even larger oval of a bowl of marble  sits on "
            "the floor with a couple of period legs bracing it.  The water within it bubbles with heat.");
   
    set_night_long("This would appear to be some sort of wash room.  A large, stone bowl full of hot water rests on top of a "
            "tiny pillar of similar material.  A circular mirror with incredible golden designs branching out of it sits "
            "above the bowl and two chairs sit on either side of it.  Another, even larger oval of a bowl of marble  sits on "
            "the floor with a couple of period legs bracing it.  The water within it bubbles with heat.");
    
    set_items(([
        "bowl" : "The marble or the stone bowl?",
        "marble bowl" : "It is full of boiling hot water.",
        "mirror" : "It has to be the most priceless thing in the house.",
                          
        
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dhouse1rm3.c",
        
                
    ]));

}

