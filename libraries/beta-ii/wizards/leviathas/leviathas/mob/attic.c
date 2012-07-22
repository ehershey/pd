#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^This attic is old and dusty.  A trunk sits in the middle of the room.");
   
    set_night_long("%^BOLD%^This attic is old and dusty.  A trunk sits in the middle of the room. ");
   
    
    set_items(([
        "trunk" : "An old trunk.",
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "down" : ROOMS "dhouse2rm2.c",
        
    ]));

}
void reset() {
  ::reset();
    if(!present("sadgirl")) 
      new(MOB "sadgirl")->move(this_object());


}

