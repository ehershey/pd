
#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : -1, "indoors" : 0]) );
set_property("plain",1);
    set_short("dark alley");
    set_long(
      "This alley is very dark.  Through the darkness not much is noticable.  "
      "Hopefully the alley isn't too long.  You get the chills being in an "
      "area such as this."
    );
    set_items(([
        "alley" : "Darkness....",
    ]));
   set_exits( ([ 
        "west" : ROOMS"room10.c",
        "enter" : ROOMS"enter1.c",
        "east" : ROOMS"room5.c",
        "south" : ROOMS"room9.c",
    ]) );
}
void reset() {
::reset();
    if(!present("shadow_st.c"))
      new(MOB"shadow_st.c")->move(this_object());
}
