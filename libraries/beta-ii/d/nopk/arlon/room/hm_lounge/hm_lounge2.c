#include <std.h>
#include <arlon.h>
inherit ROOM;

void create() {
::create();
   set_short("The Monk shrine.");
   set_long("There is a sense of peace as you enter the room, there is a shadow on half the room, and a ray of light on the "             "other . "
            "This is a shrine to the Monks of Primal Darkness. There are two statues in the middle of the room.");

        set_items(([
                "statues"      :   "Statues built in the Honor of the first high mortal Light and Dark Monk",                                "light"   :    "A block of uncarved stone.",
                "Light"   :    "A block of uncarved stone.",
                "dark"     :   "A block of uncarved stone.",
                "Dark"     :   "A block of uncarved stone.",

                        ]));
        set_properties(([
                         "light" : 1,
                         "indoors" : 1,
        ]));
        set_exits(([
                    "west" : ROOMS "hm_lounge/hm_lounge0.c",
                    "east" : ROOMS "hm_lounge/hm_lounge4.c"                

    ]));
}

