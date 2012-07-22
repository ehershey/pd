#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A roof");
    set_day_long("%^BOLD%^%^BLACK%^Although it is unearthly dark in this town, a faint %^RED%^red light %^BLACK%^creeps out of the chimney.  There are traces of %^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^on the shingles. ");
    
    set_night_long("%^BOLD%^%^BLACK%^Although it is unearthly dark in this town, a faint %^RED%^red light %^BLACK%^creeps out of the chimney.  There are traces of %^RESET%^%^RED%^blood %^BOLD%^%^BLACK%^on the shingles. ");

    set_items(([
	  "chimney" : "Many cobwebs blow gently and it looks like it's falling apart.  You could probably climb back down it.",
	  "shingles" : "It would appear that some sort of struggle took place here.  Old blood lays on the shingles.  Perhaps you could use the shingles like stairs to get down from the roof.",
          
 	
    ]));
    set_properties(([
	"outdoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"down" : ROOMS "dtown1.c",
       ]));
    add_invis_exit("down");   
    
}

void init() {
 ::init();
   add_action("chimney", "enter");
}

int chimney(string str) {
   if (!str || str != "chimney") return notify_fail("Enter what?\n");
   write("You crawl back down the chimney.");
   this_player()->move_player( ROOMS "vtower5.c");
   return 1;
}

