#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("Palace of the Cain");
    set_day_long("Lunar rock has been brilliantly constructed to form a palace north of here.  Gigantic slabs form a path to the palace while "
           "rubble decorates the frontier to the south.  The sky is jet black and stars brilliantly flicker within it.");
   
    set_night_long("Lunar rock has been brilliantly constructed to form a palace north of here.  Gigantic slabs form a path to the palace while "
           "rubble decorates the frontier to the south.  The sky is jet black and stars brilliantly flicker within it.");
   
    
    set_items(([
        "palace" : "The palace is composed of lunar rock.  There are noticable openings, save for a round sky-light on the top of a tiny outbranching chamber.",                  
        "frontier" : "It is completely desolate, lifeless, and somehow extremely beautiful."
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dpalace2.c",
                
    ]));

}


