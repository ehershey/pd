//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is where the Earth tree and the Winter tree join creating an intersection where elves come to chat and talk between their studies or between work. Many different coloured leaves cover the walkway creating a rainbow effect.");
     set_night_long("This is where the trees of Earth and Winter have grown and joined together. This part of Corinthor is a cold and hard place. The trees nearly completely void of any foliage, and are cool to the touch, as though it were the heart of Winter. The trees look strong however, even in the dark moonlight.");
     set_exits(([
  "north" : ELFROOM"earth6.c",
  "east" : ELFROOM"winter6.c",
  "southwest" : ELFROOM"winter4.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
