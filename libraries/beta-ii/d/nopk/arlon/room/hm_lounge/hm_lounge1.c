#include <std.h>
#include <arlon.h>
inherit ROOM;

void create() {
::create();
   set_short("The Kataan shrine.");
   set_long("Dark and damp, there is a earie forboding feeling about this room."
            "This is a shrine to the Kataan of Primal Darkness. There is a lone statue in the center of the room.");

        set_items(([
                "statue"    :   "A statue built in the Honor of the first high mortal Kataan",                       
                "kataan"    :   "Mephisto, the first high mortal Kataan.",
                "Kataan"    :   "Mephisto, the first high mortal Kataan.",
                        ]));
        set_properties(([
                         "light" : 0,
                         "indoors" : 1,
		        ]));
        set_exits(([
        "west" : ROOMS "hm_lounge/hm_lounge3.c",
        "east" : ROOMS "hm_lounge/hm_lounge0.c",
                
		    ]));
}
