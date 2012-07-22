#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 1]) );
    set_short("The Vampires Cave");
    set_long(
      "%^RED%^T%^BOLD%^his room is completely red.  It is "
      "now all to clear that the red colour is blood, as it "
      "seems to drip down from the ceiling.  The light is "
      "near.  %^RESET%^%^CYAN%^There is a thick fog to the north.",);
 
    set_items(([
        "red" : "%^RED%^Blood is spilt all over the floor.",
        "blood" : "It's warm...",
        "ceiling" : "You finally realize there are thousands "
              "of CORPSES staked to the ceiling!. ",
        "corpses" : "They are all fresh. ",
        "light" : "It's stronger but there is a fog you must pass. ", 
        ]));
    
    set_exits( (["north" : ROOMS "vampcav8.c",
                 "south" : ROOMS "vampcav5.c", ]) );
    
        
}
