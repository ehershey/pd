#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2,
                "no teleport" : 1]) );
   set_short("House of Teleportation");
   set_long(
            "The House of Teleportation is a very simple building "
            "off Platinum Street. It is merely an empty stone "
            "building bare of any furnishings aside from a glowing "
            "portal.");
   set_items(([
            "platinum" : "Platinum Street is to the north."
   ]));
   set_smell("default", "A dusty smell fills the room.");
   set_listen("default", "A very quiet hum echoes through the House "
	 "of Teleportation.");
   set_exits( ([ 
        "out" : ROOMS "sh_11",
	"portal" : ROOMS "tele2"]));
}
void reset() {
::reset();
    if(!present("durg")) new(MOB"durg.c")->move(this_object());
    if(!present("portal")) new(ITEMS"portal.c")->move(this_object());
}
