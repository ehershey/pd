#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
    set_short("fenton woods");
   set_property("forest",1);
    set_long(
      "Breaking out of the woods, a path leads northward. A large tree stands "
      "before what appears to be a city and forest. Off into the distance, "
      "mountains can be made out. The southern path leads back to Sindarii. "
    );
    set_items(([
	"woods" : "A few trees ",
	"trees" : "They're big and brown",
	"path" : "It goes north and southwest",
	"mountains" : "Large mountains off in the distance.",
    ]));
   set_listen("default", "Faint echoes of woodland creatures can be heard.");
   set_exits( ([ 
        "southeast" : ROOMS"forest16.c",
	"north" : ROOMS"forest3.c",
	"east" : ROOMS"forest18.c",
    ]) );
}
void reset() {
::reset();
     if(!present("vulture.c"))
new(MOB"vulture")->move(this_object());
new(MOB"vulture")->move(this_object());
}
