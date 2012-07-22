#include <std.h>
#include <pastarlon.h>
inherit ROOM;
object board;
void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_short("A small room near the Past Arlon Square");
set_long("There is not much to be seen here, except for the destruction in every direction.  This room is completely empty, with the exception of any items and people.  To the west, there is the destroyed square, and to the north, east, and south, there are buildings that look like they used to be shops, but have been destroyed.");
set_items(([
({"buildings", "shops"}) : "It looks like there could have been a supply, armour, and weapon shop, but they aren't here anymore.",
]));
}
void reset() {
    ::reset();
    if(!present("cage")){
        new("/wizards/vian/event/magicalcage")->move(this_object());
}
set_exits(([ "west" : ROOMS "square.c"]));
}

