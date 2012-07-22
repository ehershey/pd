#include <std.h>
#include <arlon.h>
inherit ROOM;

void create() {
::create();
   set_short("The Mage shrine.");
   set_long("Energy fills the air, bolts of electricity quickly zap across the room. "
            "This is a shrine to the Mages of Primal Darkness. There are statues scattered througout the room.");

        set_items(([
                "statues"      :   "Statues built in the Honor of the first high mortal Sorceror, Conjurer, "         
                                   "Pyromancer, Wizard, Necromancer, and Druid.",                               
                "pyromancer"   :   "Misery, the first high mortal Pyromancer.",
                "Pyromancer"   :   "Misery, the first high mortal Pyromancer.",
                "Sorceror"     :   "A block of uncarved stone.",
                "sorceror"     :   "A block of uncarved stone.",
                "conjurer"     :   "Tarque, the first high mortal Conjurer.",
                "Conjurer"     :   "Tarque, the first high mortal Conjurer.",
                "Wizard"       :   "Kabaal, the first high mortal Wizard.",
                "wizard"       :   "Kabaal, the first high mortal Wizard.",
                "Necromancer"  :   "Caera, the first high mortal Necromancer.",
                "necromancer"  :   "Caera, the first high mortal Necromancer.",
                "Druid"        :   "Nightshade, the first high mortal Druid.",
                "druid"        :   "Nightshade, the first high mortal Druid.",
		"electricity"  :   "You can see small bolts of electricity in the air.",
                        ]));
        set_properties(([
                         "light" : 1,
                         "indoors" : 1,
        ]));
	set_listen("default", "The sound of electricity bolts through the air.");
	set_smell("default", "You smell singed hair.");
        set_exits(([
                    "east" : ROOMS "hm_lounge/hm_lounge1.c",
                
    ]));
}
