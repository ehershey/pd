#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A room painted with blood");
    set_day_long("%^BOLD%^%^BLACK%^This room has black walls that were "
		"painted with %^RED%^blood%^BLACK%^.                   "
                "%^RESET%^%^RED%^Screams can be heard faintly and the imprints of faces "
                "and clawing hands push barely down from the ceiling and from the floor.");
   
    set_night_long("%^BOLD%^%^BLACK%^This room has black walls that were "
		"painted with %^RED%^blood%^BLACK%^.                   "
                "%^RESET%^%^RED%^Screams can be heard faintly and the imprints of faces "
                "and clawing hands push barely down from the room and from the floor."); 
    
    set_items(([
	"walls" : "They pitch black originaly, however they have been "
	          "painted over slopily with blood.",
	"blood" : "It's warm. ",
                  
        "imprints" : "They are horrifying.",
	
    ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]));
    set_exits(([
	"east" : ROOMS "2.c",
        "out" : "/d/standard/square",
    ]));
}
