//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Treetops");
     set_day_long("%^ORANGE%^The bridge leads north onto a the greatest platform of Corinthor - The Royal Palace, a place of wondrous natural beauty. The bridge iteself stretches out far above the forest floor below as the sun shines brightly in the daytime sky.%^RESET%^");
     set_night_long("%^ORANGE%^The bridge leads north to the great palace of Corinthor, a place of wondrous natural beauty. The night sky stretches on for an eternity, moons and stars relieving some of the darkness on the forest floor below.%^RESET%^");
     set_exits(([
                "north"		: ELFROOM"palacem1.c",
                "south"         : ELFROOM"bridge1-2.c" 
                ]));
     set_items(([
        ]));
}
