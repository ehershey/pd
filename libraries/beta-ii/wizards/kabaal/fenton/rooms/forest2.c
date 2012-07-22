
#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
   set_property("forest",1);
    set_short("fenton woods");
    set_long(
      "The ground is rather flat at this point. Grass grows thicker now. "
      "Civilization is off into the distant east, while woods engulf any other "
      "direction. "
    );
    set_items(([
	"grass" : "Grass comes in thicker at this point. ",
	"trees" : "They make up Fenton Woods.",
	"woods" : "Fenton Woods surround this point.",
    ]));
   set_listen("default", "Faint echoes of woodland creatures can be heard.");
   set_exits( ([ 
        "east" : ROOMS"forest1.c",
        "west" : ROOMS"forest8.c",
	"north" : ROOMS"forest5.c",
    ]) );
}
void reset() {
::reset();
     if(!present("bbear.c"))
new(MOB"bbear")->move(this_object());
}
