#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("lidelas docks");
        set_short("Lidelas Docks");
        set_long("The Lidelas Docks are very small, a large ship could never put to port at this dock. Many smaller ships fill the waters, shipping in supplies to the town. The docks looks to be well maintained, each piece of wood that makes the dock looks new. To the south, a great sea reaches to the horizon. Dozens of barrels lay scattered all around the docks, each one has a large picture of a dragon on them. The wind blows through the docks from the south, carrying in salt from the sea.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"barrels"    :  "Large barrels that have been imported from the Syntheria main lands"
	    ]));
	    set_listen("default", "The sounds of dock workers moving crates echos through the docks.");
	    set_smell("default", "The smell of sea selt fills the air.");
	    set_exits(([
			"north"		: ROOMS "lidelas005.c",
			"office"    : ROOMS "lidelasLarea.c"
        ]));

}

void reset() {
    object *childs;
    ::reset();
        childs = children(MOB"lidelas_patrol4.c");
        if(find_object(MOB"lidelas_patrol4.c")) childs -= ({ find_object(MOB"lidelas_patrol4.c") });
        if (childs==({}) || !sizeof(childs))
            new(MOB "lidelas_patrol4.c")->move(this_object());
}
