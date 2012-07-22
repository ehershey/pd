#include <std.h>
#include <terra.h>
inherit ROOM;

void create() {
::create();
    set_short("A very red room.");
    set_day_long("%^BOLD%^%^ORANGE%^Golden platters, dishes and goblets, all adorned with many beautiful and rare %^RESET%^%^CYAN%^g%^BLUE%^e%^GREEN%^m%^MAGENTA%^s %^ORANGE%^%^BOLD%^rest on rusty, golden shelves. " 
             "On the platters lay many %^MAGENTA%^%^BOLD%^br%^RED%^ai%^MAGENTA%^n%^RED%^s%^ORANGE%^, soaked with blood.  The plates have rolled up %^MAGENTA%^innar%^RED%^ds %^ORANGE%^sitting on them and the goblets are full to the rim with %^RESET%^%^RED%^cr%^BOLD%^%^RED%^i%^RESET%^%^RED%^ms%^BOLD%^o%^RESET%^%^RED%^n bl%^BOLD%^oo%^RESET%^%^RED%^d%^BOLD%^%^ORANGE%^. "                                                                      
             "                                                                                      %^RED%^Blood drips off of the shelves...  ");
   
    set_night_long("%^BOLD%^%^ORANGE%^Golden platters, dishes and goblets, all adorned with many beautiful and rare %^RESET%^%^CYAN%^g%^BLUE%^e%^GREEN%^m%^MAGENTA%^s %^ORANGE%^%^BOLD%^rest on rusty, golden shelves. " 
             "On the platters lay many %^MAGENTA%^%^BOLD%^br%^RED%^ai%^MAGENTA%^n%^RED%^s%^ORANGE%^, soaked with blood.  The plates have rolled up %^MAGENTA%^innar%^RED%^ds %^ORANGE%^sitting on them and the goblets are full to the rim with %^RESET%^%^RED%^cr%^BOLD%^%^RED%^i%^RESET%^%^RED%^ms%^BOLD%^o%^RESET%^%^RED%^n bl%^BOLD%^oo%^RESET%^%^RED%^d%^BOLD%^%^ORANGE%^. "                                                                      
             "                                                                                      %^RED%^Blood drips off of the shelves...  ");

    set_items(([
	  "platters" : "Ewww, look what's on them!",
          "brains" : "These are fresh and are beating faintly. ",
          "dishes" : "The innards of someone have been strung out, then rolled up and slopped messily onto the plates.  It almost looks like a tiny cafeteria for some insane child. ",
          "innards" : "Yuck... ",
          "goblets" : "Almost everything in here is odd and disgusting, however the goblets with their many jewels and crimson blood are rather attractive. ",    
          "blood" : "It is drippin from the shelves.",	
    ]));
    set_properties(([
	"indoors" : 1,
        "light" : 1,
	"night light" : 0,
	"no teleport" : 1,
    ]));
    set_exits(([
	"east" : ROOMS "vtower4.c", 
       ]));
}        
