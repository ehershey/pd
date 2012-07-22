#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("Kesis");
    set_long("The current street proceeds north and south.  Polished tiles of massive proportion have been laid underfoot.  There appears to be a large sort of monument south of here.  Trees of an average size have been planted in soil filled gaps in the tiling, giving an organic accent to the otherwise coldly geometric architecture.  Tinier tiles are mortared together around the tree trunk and complete what might have been an untidy arrangement.  Brilliant chimes are suspended from the tops of the walls by wooden supports.");
    
    set_items(([
             ({"material", "stone", "stone material", "marble"}) : "The marble is essentially orange now, gradiating into dark green edges.",
             "tiles" : "Giant tiles line the street floor.  They have recently been polished.",
             "chimes" : "The musical reputation of Kesis might span the globe if not for Aciri's geographic isolation.",
             "trees" : "Their breed is difficult to discern.  They seem quite fragile though.",
    ]));

    set_listen("default", "The chimes above produce beautiful, almost intelligible music.");
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "kesis63.c",
        "south" : ROOMS "kesis65.c",
    ]));
}

