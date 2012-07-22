#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^This is a large, rock area.  It looks like many rocks were placed here, a man-made structure. "
             "Through several cracks, a dull %^RESET%^%^MAGENTA%^purple %^RESET%^%^BOLD%^light shines out.");
   
    set_night_long("%^BOLD%^This is a large, rock area.  It looks like many rocks were placed here, a man-made structure. "
             "Through several cracks, a dull %^RESET%^%^MAGENTA%^purple %^RESET%^%^BOLD%^light shines out.");
    
    set_items(([
        "formation" : "The rock looks man-made.  Purple light shines out of the cracks in the rocks.",
        "trees" : "Many different, green trees.",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "east" : ROOMS "jungleent4.c",
        "west" : ROOMS "forest4.c",
		     
	 ]));
	

}
void reset() {    set_search("rocks", (: this_object(), "rocks_searching" :));
    set_search("rocks", "You push the rocks aside and pull out a crystaline, purple rock.");
}

void rock_searching() {
    message("my_action", "You push the rocks aside and pull out a glowing, purple flower.", this_player());
    message("other_action", this_player()->query_cap_name()+" finds "
      "a glowing, purple flower in the rocks.", this_object(), ({ this_player()}));
    new(ITEM "crystalf")->move(this_object());
    remove_search("rock");
}
