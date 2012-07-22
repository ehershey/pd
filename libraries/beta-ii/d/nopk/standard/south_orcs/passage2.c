#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    ::create();
    set_property("light", 2);
    set_property("night light", 2);
    set_property("no castle", 0);
    set("short", "A General's house");
    set("long",
            "This shack has been fixed up and smells much better "
            "than the rest of the village and other houses. It must "
            "belong to someone important. The shack looks pretty "
            "well fixed up.");
    set_exits( 
                (["east" : ROOMS"south_orcs/open"]) );
}

void reset() {
  ::reset();
    if(!present("general"))
      new(MOB"general.c")->move(this_object());
      present("general")->force_me("wield sword in right hand");
}
