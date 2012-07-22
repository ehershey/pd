//Made using Room generator by Nightshade
//Made by Nightshade cause the
//room was missing...

#include <std.h>
#include <rain.h>
inherit ROOM;

void create() {
    ::create();
    set_short("A house");
    set_properties( (["light" : 3, "night light" : 2, "indoors" : 1]) );
    set_long("This is a nice, cozy bedroom.  The beds are well made, and it appears that everything is in order.  This home appears to be very well kept.  ");
    set_exits( (["north" : ROOMS+"house1"
              ]) );
    set_items( ([ "bed" : "The bed is soft and comfortable looking."
                 ]) );
}

void reset() {
    ::reset();
    if(!present("child",this_object()))
        new(MOB"child.c")->move(this_object());
    if(!present("child 2",this_object()))
        new(MOB"child.c")->move(this_object());
}
