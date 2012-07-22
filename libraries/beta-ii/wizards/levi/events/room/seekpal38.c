#include <std.h>
#include <sp.h>
inherit ROOM;

void create() {
::create();
    set_short("The Great Solace");
    set_long("A throne sits here, overgrown with plant life.  It has once very beautiful, but age and natural growth have disguised it's qaulity.  "
	"The plants are in abundance everywhere, on the floor, walls and ceiling.  A soothing light shines down on everything and is particularly "
	"bright to the southeast and southwest, where it highlights two different red lights on the inner wall.  A red pool shimmers in the south.");
    
    set_items(([
          "plants" : "Plants of all different shapes and kinds fill the area.",
	  "pool" : "The pool appears to be filled with a red blood that flows in an almost intelligent manner.",
	  "red lights" : "The red lights are small and round, appearing to have a more specific purpose than the soothing light that covers everything.",
	          
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "seekpal37.c",
	"southeast" : ROOMS "seekpal40.c",
	"west" : ROOMS "seekpal39.c",
    ]));
}

