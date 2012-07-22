#include <std.h>
#include <aziraphale.h>
inherit ROOM;

void create() {
   ::create();
     set_properties((["light": 2, "night light" : 1, "town" : 1]));
     set_name("Rhondale Gates");
     set_short("Rhondale Gates");
     set_day_long("The forest clears here abruptly, leaving an open area about thirty metres wide between the treeline and the village walls. The north gates of Rhondale stand on the southern side of the clearing.");
     set_night_long("The forest clears here abruptly, giving an excellent view of the night sky. Stars give enough light to see a huge shadow to the south, the northern wall of Rhondale. A torch illuminates the village gates.");
     set_exits(([
                "north"         : KEEPROOM"zforest/x25y16.c",
                "gate"         : KEEPROOM"zvillage/outer1200.c"
                ]));
}

