#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("%^BOLD%^%^BLACK%^Eternal Darkness%^RESET%^");
    set_day_long("%^BOLD%^%^BLACK%^A large monument to Carnage has been errected here.  He is posed crossing his arms and amusedly looking down "
           "on an unsuspecting mass of mortals.  There is another statue, about half his size of death, who looks around but is unable to find "
           "Carnage.  It is extremely symbolic of something very important." );
   
    set_night_long("%^BOLD%^%^BLACK%^A large monument to Carnage has been errected here.  He is posed crossing his arms and amusedly looking down "
           "on an unsuspecting mass of mortals.  There is another statue, about half his size of death, who looks around but is unable to find "
           "Carnage.  It is extremely symbolic of something very important." );
    
    set_items(([
        "statues" : "Whoever made these must have taken quite a while with the detail.",
                  
        
        
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 1,
        "night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
        "south" : ROOMS "dtowne2n2.c",
                
                
    ]));

}


