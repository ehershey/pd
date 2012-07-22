#include <std.h>
inherit ROOM;

void create() {
::create();
   set_short("tower");
   set_long("This is yet another stairway. this one seems really long "
     "though.  the walls are blank, and not much seems to be moving.");
   set_items(([
     "walls" : "they are blank",
]));
   set_properties(([
     "light" : 2,
     "night light" : 2,
]));
   set_exits(([
     "up" : "/wizards/manex/tower8.c",
     "down" : "/wizards/manex/tower4.c",
]));
}
