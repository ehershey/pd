#include <std.h>
#include <fenton.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
    set_short("fenton woods");
   set_property("forest",1);
    set_long(
      "The ground is rather flat at this point. Grass grows thicker now. "
      "Little trees and big trees alike surround any and all that enter the "
      "forest. The canopy of the forest stretches up into the sky. Several "
      "bushes lie here. "
    );
    set_items(([
	"grass" : "Grass comes in thicker at this point. ",
	"trees" : "They make up Fenton Woods.",
	"canopy" : "The canopy here covers a lot of the sky.",
	"bushes" : "A few small bushes lie about.",
    ]));
   set_listen("default", "Faint echoes of woodland creatures can be heard.");
   set_exits( ([ 
        "northwest" : ROOMS"forest17.c",
	"north" : ROOMS"forest18.c",
	"south" : ROOMS"forest15.c",
	"east" : ROOMS"forest10.c",
    ]) );
}
void reset() {
::reset();
     if(!present("vulture.c"))
new(MOB"vulture")->move(this_object());
new(MOB"bbear")->move(this_object());
}
