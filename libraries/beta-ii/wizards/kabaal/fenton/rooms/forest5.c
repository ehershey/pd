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
      "forest. The canopy of the forest stretches up into the sky. "
    );
    set_items(([
	"grass" : "Grass comes in thicker at this point. ",
	"trees" : "They make up Fenton Woods.",
	"canopy" : "The canopy here covers a lot of the sky.",
    ]));
   set_listen("default", "Faint echoes of woodland creatures can be heard.");
   set_exits( ([ 
        "west" : ROOMS"forest9.c",
	"north" : ROOMS"forest11.c",
	"south" : ROOMS"forest2.c",
    ]) );
}
