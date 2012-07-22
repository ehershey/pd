#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 1, "night light" : 0,
                "no teleport" : 1]) );
   set_long(
            "%^BOLD%^%^BLUE%^Underneath the water of the pond is warm. "
            "It is hard to see very far in any direction. The water "
            "gets darker as it gets father down.%^RESET%^ ");
   set_items(([
            "water" : "The farther down it goes, the darker the "
		 "water gets.",
            "pond" : "The pond water is everywhere. "
   ]));
   set_listen("default", "Bluubb.. bluubb.. bluubb.... ");
   set_exits( ([ 
        "north" :  ROOMS "dp_2",
        "southeast" :  ROOMS "dp_6",
        "up" :  ROOMS "p_10",
	"northeast" :  ROOMS "dp_1",
	"south" : ROOMS  "dp_8"]));
    if(!present("piranha")) new(MOB"pir4.c")->move(this_object());
    if(!present("eel")) new(MOB"eel.c")->move(this_object());
    if(!present("eel 2")) new(MOB"eel.c")->move(this_object());
}
