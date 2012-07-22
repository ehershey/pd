#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("Kesis");
    set_long("There is a bench on either side of the street.  Each bench is a combination of a light mahogany wood with a golden metal frame.  The shiny tiles of the street's floor are gigantic in size.  Beautiful trees line the street walls about three meters apart from each other and look well cared for, being structurally delicate but perfectly groomed.  Chimes are mounted on the tops of the walls.");
    
    set_items(([
             "mahogany" : "An elegant wood.",
             ({"gold", "frame"}) : "The bench frame is a masterpiece.",
             "street" : "The street is beautiful and well cared for.",
             "bench" : "Each bench might have cost a sizeable fortune to create.",
             ({"material", "stone", "stone material", "marble"}) : "What appears to be marble is orange in colour and fades at its edges into green.",
             "tiles" : "Giant tiles line the street floor.  They have recently been polished.",
             "chimes" : "The musical reputation of Kesis might span the globe if not for Aciri's geographic isolation.",
             "trees" : "They seem quite fragile, with beautiful flowers budding on them.",
             "flowers" : "A furious red, these buds slowly open to reveal petals like phoenix wings.",
    ]));

    set_listen("default", "You can hear the chimes frolic around in the wind.");
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "kesis61.c",
        "south" : ROOMS "kesis63.c",
    ]));
}

