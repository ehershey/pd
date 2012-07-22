#include <std.h>
#include <fenton.h>
inherit ROOM;

void create() {
::create();
    set_short("Fenton Shopkeep");
    set_long(   "A small room in the corner of the city.  This shopkeep "
                "is rundown with an uptight shopkeeper. ");
       set_properties(([
        "light" : 2,
        "night light" : 0,
    ]));
set_property("plain",1);
    set_exits(([
        "west" : ROOMS "room11.c",
    ]));
}

void reset() {
::reset();
       if (!present("contour")){
        new(MOB"contour")->move(this_object());
}
}
