#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("Deathless hall");
    set_day_long("%^BOLD%^A fountain in the middle of the hall trickles"
              " out %^RED%^blood%^RESET%^%^BOLD%^.");
    
    set_night_long("%^BOLD%^A fountain in the middle of the hall"
              " trickles out %^RED%^blood%^RESET%^%^BOLD%^.");

    


    set_items(([
          "fountain" : "Blood trickles out, sparkling.",                        

                
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "vhall3.c",
        "south" : ROOMS "vhall1.c",
       ]));
}
