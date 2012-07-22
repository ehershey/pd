//Amarael/Aziraphale/Prator/Azirel
#include <std.h>
#include <corinthor.h>

inherit ELFOBJ"elfroom.c";

void create()  {
   ::create();
     set_properties(([ "light" : 3, "night light": 2, "forest" : 1 ]));
     set_short("Corinthor");
     set_day_long("At the northern edge of the ring of life sits the Summer tree, it's branches are strong and filled with dark green leaves in their prime. Unlike the south side of Corinthor the path is completely free of any fallen leaves. Many elven children come here to play in heat of the Summer sun.");
     set_night_long("At the northern edge of the ring of life sits the Summer tree, it's branches are strong and filled with dark green leaves in their prime. Unlike the south side of Corinthor the path is completely free of any fallen leaves. In the day many elven children play here, but for now they are all in bed.");
     set_exits(([
  "southeast" : ELFROOM"summer3.c",
  "west" : ELFROOM"summer1.c",
                ]));
     ELFOBJ"lookat"->forestlook();
}
