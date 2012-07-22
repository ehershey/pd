//stormy
#include <std.h>
#include <tirun.h>
inherit ROOM;
void create() {
    ::create();
    set_short("a cave");
    set_properties( (["light" : 1, "night light" : 1, "indoors" : 1]) );
    set_listen("default", "Water dripping can be heard");
    set_smell("default", "It smells of dampness here.");
    set_long("Inside a cave.  The walls are slick.");
    set_exits( (["west" : ROOMS+"blah"
              ]) );
    set_items( ([ "walls" : "Moisture drips down the walls making them slick."
                 ]) );
}
void reset() {
    ::reset();
    if(!present("gorilla",this_object()))
        new(MOB+"gorilla")->move(this_object());
}
