#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^The tiny bridge crumbles, ancient and probably ready to collapse.  The pitch black sky is lit by "
             "%^YELLOW%^f%^BLUE%^lick%^YELLOW%^erin%^BLUE%^g light%^YELLOW%^ni%^BLUE%^ng%^BLACK%^ every few moments, during which "
	     "shadows dance across the spire.");
   
    set_night_long("%^BOLD%^%^BLACK%^The tiny bridge crumbles, ancient and probably ready to collapse.  The pitch black sky is lit by "
             "%^YELLOW%^f%^BLUE%^lick%^YELLOW%^erin%^BLUE%^g light%^YELLOW%^ni%^BLUE%^ng%^BLACK%^ every few moments, during which "
	     "shadows dance across the spire.");
    
    set_items(([
        "path" : "The path, a slender and crumbling arm of a bridge that leads to a spire northeast of here."
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "southwest" : ROOMS "dtowne8n.c",
	"northeast" : ROOMS "dtowndsp2.c",
		     
	 ]));
    
}
void reset() {
  ::reset();
    if(!present("shadowbeast")) 
      new(MOB "shadowbeast")->move(this_object());
}

