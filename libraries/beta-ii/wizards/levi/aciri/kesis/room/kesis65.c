#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("Kesis");
    set_long("There is a junction here where two streets meet, one descending from the north and the other extending east.  In the southwestern corner, a large monument to Carnage has been constructed.  Adorned with rubies, gold, Tiger's Eye and several other red and orange stones, the monument depicts the god's contribution to the city and his death simultaneously.  His right side, leading east and out of the city, is made of white marble and symbolizes the eradication of his magical presence on Aciri by outside forces.  His left side, leading northwest and into the city, is blazing with all of those jewels, and clearly indicates the people's belief that his spirit is inherent in the heart of the city.  The orange tinge in the city's marble is extremely prominent starting here and leads into the north.");
    
    set_items(([
             ({"material", "stone", "stone material", "marble"}) : "The marble is essentially orange now, gradiating into dark green edges.",
             "tiles" : "Giant tiles line the street floor.  They have recently been polished.",
             "chimes" : "The musical reputation of Kesis might span the globe if not for Aciri's geographic isolation.",
             "statue" : "The statue, half bled of colour and vibrancy, is an effective reminder to citizens who come and go as to where their home truly lies.",
               
    ]));

    set_listen("default", "The chimes play a somber tune here, mourning Carnage.");
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
      new(ITEM "carnage.c")->move (this_object());
    set_exits(([
        "north" : ROOMS "kesis64.c",
        "east" : ROOMS "kesis66.c",
    ]));
}

