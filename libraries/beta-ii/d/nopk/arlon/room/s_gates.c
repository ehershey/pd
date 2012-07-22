#include <std.h>
#include <arlon.h>

inherit ROOM;

void create()
{
 ::create();
   set_property("plain", 1);
 set_short("A path");
 set_long("The green grass stands tall waving in the wind. The ground "
          "is a little moist and foot prints and an assortment of "
          "animal foot prints. The breeze from the sparking blue ocean "
          "to the west blows lightly.");
 set_listen("default", "The breeze blows on you lightly.");
 set_smell("default", "The smell of sea water fills the air.");

  set_exits( (["west"  : "/d/nopk/tirun/beach/9,4,0",
               "east"  : ROOMS "plains2",
            ]) );
}