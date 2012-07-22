//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("Even in the day, the joining between the Winter and the Moons is cold and dark, all the warmth and light being sucked into the two trees on either side. To the south is a bridge leading in and out of Corinthor. Elves walk by constantly on their daily business.");
     set_night_long("At night this place shines slightly with a white light, the tree of the Moons singing with it's namesakes gliding through the sky. To the south is a bridge leading in and out of the treetop town of Corinthor. There is hardly anyone around here at night, as it is much too cold and dark.");
     set_exits(([
  "south" : ELFROOM"bridge2-1.c",
  "southwest" : ELFROOM"winter1.c",
  "north" : ELFROOM"moons5.c",
  "southeast" : ELFROOM"moons3.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
