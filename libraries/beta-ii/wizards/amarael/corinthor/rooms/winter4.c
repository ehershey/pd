//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This is where the Earth tree and the Winter tree join creating an intersection where elves come to chat and talk between their studies or between work. Many different coloured leaves cover the walkway creating a rainbow effect.");
     set_night_long("This is where the Earth and Winter tree walkways intersect and the fallen leaves from both trees create a carpet effect muffling your footsteps. The trees glow softly in the hidden lights among both trees giving off a serene feeling.");
     set_exits(([
  "west" : ELFROOM"earth1.c",
  "northeast" : ELFROOM"winter5.c",
  "south" : ELFROOM"winter3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
