//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("The Earth and Spring trees are joined here to create just a single path around both heading to the east. In the daylight it can be seen that that path continues into Orn'Atar. The platforms seperate to the northwest and southwest, going around Spring and Earth respectively.");
     set_night_long("The Earth and Spring trees are joined here to create just a single path around both heading to the east. In the dark it is hard to make out where it leads to. Two more paths can be seen, heading northwest and southwest, leading around the trees of Spring and Earth respectively.");
     set_exits(([
  "northwest" : ELFROOM"spring1.c",
  "east" : ELFROOM"earth5.c",
  "southwest" : ELFROOM"earth3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
