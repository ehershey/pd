//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("Here, where the Sun and spring are grown together, is where the much of the life of Corinthor lies. It has been chosen as the place for the local healer's guild, to take advantage of the inherent flow of new life surrounding this place.");
     set_night_long("Even at night this can clearly be seen as a place where the Trees of Sun and Spring meet and bring new life. This has been chosen as the place for the local healer's guild, to take advantage of the inherent flow of life surrounding this place.");
     set_exits(([
  "west"  : ELFROOM"healguild.c",
  "south" : ELFROOM"spring4.c",
  "northwest" : ELFROOM"sun7.c",
  "east" : ELFROOM"sun5.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
