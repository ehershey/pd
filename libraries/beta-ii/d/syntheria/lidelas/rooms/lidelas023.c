#include <std.h>
#include <lidelas.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("alley");
        set_short("Alley");
        set_long("A small alley way made of worn cobble stone. The alley is very thin, no size carriage could make it down this path. There is a lot of garbage spread out all over the alley, this must be the place where people of the town come to dump things illegally. A slight breeze blows through the alley, keeping it smelling fresh despite the garbage. The buildings on both sides of the alley reach several stories into the air, blocking out most of the sky. The buildings are made of a very nice red brick, however there are no windows on the buildings that face the alley way.  ");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"garbage"      :   "A lot of trash that fills the alley, disgusting",
	    ]));
	    set_listen("default", "The alley is silent.");
	    set_smell("default", "The breeze keeps the air fresh.");
	    set_exits(([
			"north"		: ROOMS "lidelas022.c",
            "south"     : ROOMS "lidelas024.c",
        ]));
}

