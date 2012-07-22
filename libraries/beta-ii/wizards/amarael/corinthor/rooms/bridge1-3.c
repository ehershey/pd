//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ROOM;

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor Treetops");
     set_day_long("%^ORANGE%^This bridge at the north end of Corinthia leads to and from the palace and Orn'Atar, the tree that holds the entire elven city in it's branches. During the day the bridge rocks gently from those who walk across it.%^RESET%^");
     set_night_long("%^ORANGE%^This bridge at the north end of Corinthia leads to and from the palace and Orn'Atar, the tree that holds the entirety of the elven village. At night it is rather peaceful here, with the stars casting a dim light.%^RESET%^");
     set_exits(([
                "north"         : ELFROOM"bridge1-2.c",
                "south"         : ELFROOM"sun3.c" 
                ]));
     ELFOBJ"lookat"->forestlook();
}
