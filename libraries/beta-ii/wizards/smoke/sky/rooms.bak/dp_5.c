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
        "northwest" :  ROOMS "dp_1",
        "up" :  ROOMS "p_12",
	"southwest" :  ROOMS "dp_7",
	"south" : ROOMS  "dp_10"]));
    if(!present("piranha")) new(MOB"pir3.c")->move(this_object());
    if(!present("piranha 2")) new(MOB"pir3.c")->move(this_object());
    if(!present("piranha 3")) new(MOB"pir4.c")->move(this_object());
}
