#include <std.h>
#include <arlon.h>
inherit ROOM;

void create() {
::create();
   set_short("The Rogue shrine.");
   set_long("Faint shadows dart into the darkness, you see one three rays of light coming from an unknown light source.  "               "This is a shrine to the Rogues of Primal Darkness. There are three statues in the middle of theroom.");

        set_items(([
                "statues"      :   "Statues built in the Honor of the first high mortal Jester, Assassin, and Thief",                        "thief"        :   "A block of uncarved stone.",
                "Thief"        :   "A block of uncarved stone.",
                "Assassin"     :   "A block of uncarved stone.",
                "assassin"     :   "A block of uncarved stone.",
                "jester"       :   "A block of uncarved stone.",
                "Jester"       :   "A block of uncarved stone.",
		"shadows"      :   "You can see small shadows with beady %^RED%^eyes%^RESET%^.",
		"eyes"         :   "Beady %^RED%^eyes%^RESET%^.", 

                        ]));
        set_properties(([
                         "light" : 0,
                         "indoors" : 1,
        ]));
        set_exits(([
                    "west" : ROOMS "hm_lounge/hm_lounge2.c",
                            
    ]));
}

