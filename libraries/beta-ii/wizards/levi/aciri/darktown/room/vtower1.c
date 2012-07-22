#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A room painted with blood");
    set_day_long("%^BOLD%^%^BLACK%^The %^YELLOW%^stars %^BLACK%^can be seen outside of glass "
                "windows on either side of these stairs.  Little light shines in.  The ceiling "
                "seems to be composed of some black, waving tissue.  Pieces of it fall down.  "
                "There are stairs leading down and up.  Out the left window, a vast planet can "
                "be seen, however looking out the right window, there seems to be a suspicious "
                "darkness. " );
   
    set_night_long("%^BOLD%^BLACK%^It is dark at night.  The %^YELLOW%^stars %^BLACK%^ can "
                "just barely be seen, as this darkness is so horrifying.  Paintings of pale "
                "figures seem to move slowly and stealthily along the walls, however this area "
                "of the tower seems strangely empty.  Stairs lead up and down. "); 
    
    set_items(([
	"stairs" : "%^BOLD%^%^BLACK%^The stairs are made of bones and flesh.  Just walking on "
                "them generates a squishing sound and blood floods out from the pressure of "
                "your feet.",
	"stars" : "%^BOLD%^%^BLACK%^The %^YELLOW%^stars %^BLACK%^burn brightly . ",
                  
        "light" : "%^BOLD%^Just a little %^YELLOW%^light %^RESET%^%^BOLD%^makes it in.",
	
        "glass" : "%^BLUE%^%^BOLD%^The glass seems tinted blue. ",
      
        "windows" : "The walls on either side of you are completely made of glass. ",

        "ceiling" : "Blood drips down from faults in the ceiling. ",

        "tissue" : "The tissue on the ceiling is like gorey flesh. ",

        "planet" : "It is the most beautiful thing you've ever seen...  a blue and green globe. ",
      
        "darkness" : "Eyes seem to pierce your skin. ",

        "paintings" : "The paintings seem to move as you shift your field of vision and stop "
                "when you look back. ",

        "walls" : "They are made of a greyish, dull, stone.  White outlines of pale figures "
               "seem to move. ",

    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 1,
	"no teleport" : 1,
    ]));
    set_exits(([
	"up" : ROOMS "vtower2.c",
     ]));
}
