#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("The Gate Entrance to Kesis");
    set_long("An astoundingly tall gate has been built west of here.  It is composed of two enormous pillars, each of "
	"which is easily fifty meters tall.  A somewhat smaller, arch shaped piece of stone sits atop both of the "
	"pillars, joining them together.  Several buildings of every description can be seen from here, although from "
	"this vantage point it is difficult to gauge the size of the Kingdom.");
    
    set_items(([
          "tiles" : "Enormous tiles have been placed here to cover the ground.",
                             
	  "pillars" : "The enormous pillars are green-tinted.",
	          
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
        "outdoors" : 1,
    ]));
    set_exits(([
        "west" : ROOMS "kesis75.c",
    ]));
}

