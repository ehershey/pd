#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 1, "night light" : 0,
                "no teleport" : 1]) );
   set_long(
            "%^BLUE%^Underneath the water of the pond is warm. "
            "It is hard to see very far in any direction. The water "
            "gets darker as it gets father down. A large cave is "
	    "built into the northern wall.%^RESET%^ ");
   set_items(([
            "water" : "The farther down it goes, the darker the "
		 "water gets.",
            "pond" : "The pond water is everywhere. ",
	    "cave" : "A cave is in the north wall."
   ]));
   set_listen("default", "Bluubb.. bluubb.. bluubb.... ");
   set_exits( ([ 
        "southwest" :  ROOMS "ddp_2",
        "up" :  ROOMS "dp_4",
	"southeast" :  ROOMS "ddp_3",
	"cave" : ROOMS  "cave"]));
    if(!present("piranha")) new(MOB"pir3.c")->move(this_object());
    if(!present("piranha 2")) new(MOB"pir4.c")->move(this_object());
    if(!present("eel")) new(MOB"eel.c")->move(this_object());
    if(!present("squid")) new(MOB"squid.c")->move(this_object());
}
