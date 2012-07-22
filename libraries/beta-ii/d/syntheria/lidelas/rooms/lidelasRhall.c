#include <std.h>
#include <lidelas.h>

inherit HALL;

void create()
{
    ::create();
        set_name("rogue hall");
        set_short("Rogue Hall");
        set_long("This is the hall of rogues, it is a small little room lit by only a few candles. It is dirty, and the air is thick with smoke. The floor is covered with many soiled carpets, and not one of them matches another. The walls are lines with many fancy and unique daggers, most likely stolen from travelers. There are a few small tables up against each wall, most of them are covered in papers.");  
        set_properties( ([ 
        "no attack"   : 1,
        "no magic"    : 1,
        "no bump"     : 1,
        "light"       : 2,
        "night light" : 2,
        "no steal"    : 1,
        "indoors"     : 1,
        "town"        : 1, ]) );
        set_items(([
    	
	    ]));
	    set_listen("default", "It is very quiet, only whispers can be heard.");
	    set_smell("default", "The smell of something burning permeates the air.");
	    set_exits(([
			"up"        : ROOMS "lidelas036.c",
        ]));
}

void reset() {
   ::reset();
if (!present("jeale", this_object()))
     new(MOB"Jeale_Keljorm.c")->move(this_object());
}
