#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("rafore street");
        set_short("Rafore Street");
        set_long("Rafore Street runs through the center of Lidelas, it runs north and south. A large hall lies to the west, the hall towers in to the air. The entrance to the hall is a large doorway with a very sharp point at the top of the doorway, dozens of glass windows line the fron of the hall. The street is made up of large cobble stones, finely polished. The street is very wide, it looks like it was designed to allow a large amount of traffic to freely move about. On each side of the street, large buildings have been built. Every building is at least four stories high, there looks to be a series of arches above every window. The arches lead up to tall points. Each level of the buildings has a small ledge from which many small stone gargoyles are carved into the ledges.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"gargoyles"    :  "They are not very large, and seem to be carved into the building."
	    ]));
	    set_listen("default", "The sound of carts moving on the stone steets can be heard in all directions.");
	    set_smell("default", "The smell of sea selt fills the air.");
	    set_exits(([
			"north"		: ROOMS "lidelas004.c",
			"south"		: ROOMS "lidelas007.c",
			"east"		: ROOMS "lidelas008.c",
			"west"		: ROOMS "lidelas006.c",
        ]));
        add_pre_exit_function("west", "go_west");
}

int go_west() {
  if(!this_player()->is_player()) return 0;
  return 1;
}

void reset() {
   ::reset();
if (children(MOB"bertwald_hereric.c")==({})||
    sizeof(children(MOB"bertwald_hereric.c"))<1)
     new(MOB "bertwald_hereric.c")->move(this_object());
}
