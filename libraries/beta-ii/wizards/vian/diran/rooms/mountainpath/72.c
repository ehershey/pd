#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( (["light" : 2, "indoors":1, "night light" : 1, ]) );
    set_short( "an entrance" );
    set_long("The end of the narrow path seems to have ended outside the Duergar city.  There is a large wall of fortification to the east.  The smoke is much less thick down here, but it is still fairly overwhelming.  The smallest sounds echo from the walls, making it very noisy.");
set_exits(([ "west" : ROOMS"duergar/1",
"up" : ROOMS"mountainpath/71.c",
]));
    set_items( ([
({"torches"}):"The torches seem to be lit with a magical flame that doesn't flicker or go out.",
"smoke":"The smoke is thick due to lack of ventilation.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");

        if(!present("dguard"))
          new(MOB "dguard")->move(this_object());
          new(MOB "dguard")->move(this_object());

}
