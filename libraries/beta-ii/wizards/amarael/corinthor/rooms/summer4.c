//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("Here, where Summer and Stars are joined, is an enchanted place. A warm breeze silently whistles through the air, rustling the thousands of green leaves, making sparkling effects with the shadows. The area has a peaceful and caring aura, many fall in love here, and it is where the Corinthian temple is located.");
     set_night_long("Here, where Summer and Stars are joined, is an enchanted place. A warm breeze silently whistles through the air, rustling the thousands of green leaves, making sparkling effects with the shadows. The area has a peaceful and caring aura, many fall in love here, and it is where the Corinthian temple is located.");
     set_exits(([
  "east" : ELFROOM"stars1.c",
  "southwest" : ELFROOM"summer5.c",
  "north" : ELFROOM"summer3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
