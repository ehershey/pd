#include <std.h>
#include <radyne.h>

inherit ROOM;

void create() {
   ::create();
   set_properties( ([
      "outdoors" : 1,  "light" : 2,  "night light" : 1,  "town" : 1,
   ]) );
   set_short("Radyne Nova - Alley");
   set_long(
      "%^BOLD%^%^BLUE%^Radyne Nova: Alley%^RESET%^\n"
      ""
   );
   set_night_long(
      "%^BOLD%^%^BLUE%^Radyne Nova: Alley%^RESET%^\n"
      ""
   );
   set_exits( ([
      "east" : ROOMS "square",
      "west" : ROOMS "wsquare2",
   ]) );
}


