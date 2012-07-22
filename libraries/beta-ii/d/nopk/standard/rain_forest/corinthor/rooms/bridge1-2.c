//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Treetops");
     set_day_long("%^ORANGE%^This is the middle point of the bridge that leads to and from the Corinthian palace. To the south the bridge leads to Orn'Atar, the mighty tree that holds all of the elven village in it's branches. The sun shines down from above.%^RESET%^");
     set_night_long("%^ORANGE%^This is the middle point of the bridge leading to and from the Corinthian palace. To the south, the bridge continues and eventually leads to Orn'Atar, which holds the entirety of the elven village in it's mighty branches.%^RESET%^");
     set_exits(([
                "north"         : ELFROOM"bridge1-1.c",
                "south"         : ELFROOM"bridge1-3.c" 
                ]));
     ELFOBJ"lookat"->forestlook();
}

