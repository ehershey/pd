#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^This is the entrance to a tiny jungle-area.  Many %^GREEN%^green %^BLACK%^, lush trees and vines "
             "grow everywhere.  The darkness of the sky seems less powerful here and there are noises from rare animals all around. ");
   
    set_night_long("%^BOLD%^%^BLACK%^This is the entrance to a tiny jungle-area.  Many %^GREEN%^green %^BLACK%^, lush trees and vines "
             "grow everywhere.  The darkness of the sky seems less powerful here and there are noises from rare animals all around. ");
    
    set_items(([
        "vines" : "The vines are all over the place.",
        "trees" : "Many different, green trees.",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dtowne7.c",
        "south" : ROOMS "jungleent2.c",
		     
	 ]));
	

}
void reset() {
  ::reset();
    if(!present("silversnake")) 
      new(MOB "silversnake.c")->move(this_object());
}

