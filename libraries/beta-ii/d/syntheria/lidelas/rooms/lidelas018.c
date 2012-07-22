#include <std.h>
#include <lidelas.h>

inherit ROOM;



void create()
{
    ::create();
        set_name("side road");
        set_short("Side road");
        set_long("A small path that is now used as a road. It connects two of the large streets in Lidelas, Feng avenue, and Eni avenue. There are a few small houses here, of very different style then most of the town. The houses look to be just simple wooden constructions, with no carvings or fancy statues. Smoke bellows out of small chimneys on all of the roofs. Candle light can be seen coming from the small windows in each house.");  
        set_properties( ([
        "light"       : 2,
        "night light" : 2,]) );
        set_items(([
    	"houses"    :  "Houses built out of wood, nothing very special about them."
	    ]));
	    set_listen("default", "It is rather quiet in this part of town.");
	    set_smell("default", "The smell of smoke is everywhere.");
	    set_exits(([
			"north"		: ROOMS "lidelas019.c",
			"south"		: ROOMS "lidelas017.c",
			"enter"     : ROOMS "lidelasHouse2.c",
        ]));
        add_pre_exit_function("enter", "go_enter");
}

int go_enter() {
  if(!this_player()->is_player()) return 0;
  return 1;
}


