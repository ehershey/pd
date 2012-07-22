#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
  set_property("plains",1);
 set_short("A path");
 set_long("The green grass stands tall waving in the wind. The ground "
          "is a little moist and foot prints and an assortment of "
          "animal foot prints. There are a couple short trees "
          "scattered around. There is an oasis to the north.");
 set_listen("default", "The breeze blows on you lightly.");
 set_exits( ([ "north": ROOMS "oasis",
               "south": ROOMS "plains8" ]) );
}

