#include <std.h>
#include <terra.h>
inherit ROOM


void create() {
::create()

    set_short("%^RED%^Into the Volcano%^RESET%^")

    set_day_long("%^RED%^Fire is everywhere."
              "F%^BOLD%^l%^YELLOW%^a%^RESET%^%^ORANGE%^m%^RED%^e"
              "%^YELLOW%^s %^RESET%^%^RED%^dance across the %^BOLD%^ "
              "%^BLACK%^Molten %^RED%^Lava %^RESET%^%^RED%^.  You "
              "think you can hear dwarven songs not far off. ")

   
    set_night_long("%^RED%^Fire is everywhere."
              "F%^BOLD%^l%^YELLOW%^a%^RESET%^%^ORANGE%^m%^RED%^e"
              "%^YELLOW%^s %^RESET%^%^RED%^dance across the %^BOLD%^ "
              "%^BLACK%^Molten %^RED%^Lava %^RESET%^%^RED%^.  You "
              "think you can hear dwarven songs not far off. ")

    
    set_items(([
	"flames" : "%^RED%^THEY BURN!",
	"molten lava" : "The Lava cannot cool down in such a hot area ",
                  
        	
    ]))

    set_properties(([
	"light" : 1,
	"night light" : 0,
    ]))

    set_exits(([
	"out" : ROOMS "out.c",
        "north" : ROOMS "volcano2.c",
    ]))

}
