#include <arlon.h>
#include <std.h>
inherit ROOM;

void create() {
::create();
   set_short("The Fighter shrine.");
   set_long("Sounds of glory and battlerage echo through your ears.  Medals of honor adorn the walls."	 	    	    	    "This is a shrine to the Fighters of Primal Darkness. There are six statues scattered about the room.");

	set_items(([
		"statues"           :   "Statues built in the Honor of the first high mortal Soldier, Warrior, Ranger, "   
					"Paladin, Antipaladin, and Knight.",
		"Soldier"           :   "A block of uncarved stone.",
		"soldier"           :   "A block of uncarved stone.",
		"warrior"           :   "A block of uncarved stone.",
		"Warrior"           :   "A block of uncarved stone.",
		"ranger"            :   "A block of uncarved stone.",
		"Ranger"            :   "A block of uncarved stone.",
		"Paladin"           :   "A block of uncarved stone.",
		"paladin"           :   "A block of uncarved stone.",
		"antipaladin"       :   "A block of uncarved stone.",
		"Antipaladin"       :   "A block of uncarved stone.",
		"Knight"            :   "A block of uncarved stone.",
		"knight"            :   "A block of uncarved stone.",
 		"medal" 	    :   "Several different medals of honor.",
 		"medals" 	    :   "Several different medals of honor.",

			]));
        set_properties(([
                         "light" : 3,
          		 "indoors" : 1,
        ]));
	set_listen("default", "Sounds of glory and battlerage echo.");
        set_exits(([
                    "south" : ROOMS "hm_lounge/hm_lounge0.c",
		            
    ]));
}
