
#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A glass path");
    set_day_long("%^CYAN%^Amazingly, after travelling only a few steps, "
"a supernatural light ignites and reveals the surroundings.  The whole "
"path has been constructed of glass.  The glass is tinted dark blue bec"
"ause of the light, which is generated below it. ");
    
    set_night_long("%^CYAN%^Amazingly, after travelling only a few step"
"s, a supernatural light ignites and reveals the surroundings.  The who"
"le path has been constructed of glass. The glass is tinted dark blue b"
"ecause of the light, which is generated below it. ");

    set_items(([
          "path" : "The path has been lit by a blue light produced und"
	      "erneath the glass.",
          "light" : "The blue light is produced from below the glass p"
	      "ath, perhaps in some underground room?",
          
        
    ]));
    set_properties(([
        "outdoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "north" : ROOMS "dtownmp2.c",
        "south" : ROOMS "dtown1.c",
        
       ]));
    add_invis_exit("");   
}

