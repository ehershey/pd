#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1]) );
   set_long(
            "%^GREEN%^The path ends here before a gigantic ant "
            "hill. Ants can be seen climbing all over the hill.  "
	    "The trees and plants totally surround this spot "
	    "except for a small break to the south.");
   set_items(([
            "trees" : "There are plenty of trees on each side of the path. "
                        " They are all different sizes and varieties, "
			"but they all have an exotic look to them.",
            "path" : "The main path is south of here. ",
            "plants" : "All sorts of different plant species grow in the jungle. "
		 "Most of them are huge compared to more domesticated plants "
		 "common to the land of Tirun.",
            "canopy" : "The canopy is very thick, allowing little or no access "
                "to the vastness of the sky. ",
            "break" : "This is a small break in the jungle. It leads south "
                "towards the main path. "
   ]));
   set_smell("default", "The thick air is almost suffocating.");
   set_listen("default", "The buzzing of large insects from all over. ");
   set_exits( ([ 
        "climb" :  ROOMS "hill1",
	"south" : ROOMS  "n_3"]));
set_invis_exits(({"climb"})); 
    if(!present("ant")) new(MOB"fire1.c")->move(this_object());
    if(!present("ant 2")) new(MOB"ant4.c")->move(this_object());
    if(!present("ant 3")) new(MOB"ant1.c")->move(this_object());
    if(!present("ant 4")) new(MOB"fire1.c")->move(this_object());
}
int go_climb() {
    if(present("ant")) {
        write("The %^RED%^fire ant%^RESET%^ prevents you from climbing!");
        return 0;
    }
    else return 1;
}
void reset() {
    ::reset();
    if(!present("hill")) new( ITEMS "hill.c")->move(this_object());
}

