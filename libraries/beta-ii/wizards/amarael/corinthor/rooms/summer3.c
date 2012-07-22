//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("This part of the Summer tree offers an excellent view of the northeastern forest, stretching on for hundreds of feet before the trees compeltely obscure the view. The forest floor can even be seen, with all the animals just tiny dots scurrying about. This tree filled with dark green leaves, and despite the shade, it is rather hot.");
     set_night_long("This part of the Summer tree offers an excellent view of the northeastern forest, stretching on for just a hundred feet before the darkness obscures the view. The ofrest floor below can barely be made out in the moonlight, with tiny points of darkness showing the movement of animals. This tree filled with dark green leaves that sway with a hot breeze.");
     set_exits(([
  "south" : ELFROOM"summer4.c",
  "northwest" : ELFROOM"summer2.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
