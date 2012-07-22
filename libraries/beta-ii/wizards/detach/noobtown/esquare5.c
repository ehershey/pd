#include <std.h>
#include <radyne.h>

inherit ROOM;

void create() {
   ::create();
   set_properties( ([
      "outdoors" : 1,  "light" : 2,  "night light" : 1,  "town" : 1,
   ]) );
   set_short("Adian Highway and Square Street Intersection");
   set_long(
      "%^BOLD%^%^BLUE%^Adian Highway and Square Street Intersection%^RESET%^\n"
      ""
   );
   set_night_long(
      "%^BOLD%^%^BLUE%^Adian Highway and Square Street Intersection%^RESET%^\n"
      ""
   );
   set_exits( ([
      "west" : ROOMS "esquare4",
      "east" : ROOMS "esquare6",
      "north" : ROOMS "tr11n",
      "south" : ROOMS "tr11s",
   ]) );
}


