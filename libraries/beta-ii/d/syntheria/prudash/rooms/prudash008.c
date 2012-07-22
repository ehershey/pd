#include <std.h>
#include <prudash.h>

inherit ROOM;

void create()
{
    ::create();
        set_name("prudash");
        set_short("Prudash");
        set_long("Many small buildings are built into the trees, each building looks to have been built from scrap lumber. The trolls of this village must have stolen the lumber from the town of Lidelas. Small torches are mounted to the buildings, keeping the town lit no matter the time. There are arrows lodged in the trees at random spots, it looks like they came from the ground. The people from Lidelas must come here every so often to try and eliminate the troll village.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,
        "forest"      : 2,
        ]) );
        set_items(([
    	"building"     :   "Small wooden buildings high above the ground.",
    	"torches"      :   "Small torches line the buildings, lighting the village",
    	"bridge"       :   "Long old bridges made of scrap wood."
        ]));
	    set_listen("default", "The bridges creak with each step as the wind howls.");
	    set_smell("default", "The fresh forest air smells nice.");
	    set_exits(([
			"northeast"	: ROOMS "prudash012.c",
			"west"	    : ROOMS "prudash007.c",
			"southeast"	: ROOMS "prudash009.c",
        ]));
}

void reset() {
   ::reset();
if (!present("peasant", this_object()))
     new(MOB"troll_peasant.c")->move(this_object());

}
