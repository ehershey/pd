#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;
void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell
overpowers most everything else.");
set_listen("default", "The clamor of a busy city fills your ears.");
set_short("Zolenia Palace");
set_long("%^BOLD%^%^BLACK%^The palace is one large, long, narrow room.  The walls are covered in paintings of past Valsharess of the drow.  The ground is made of polished onyx, containing a pathway leading toward the Valsharess and her throne, or back toward the city.  There are racks of armour and weapons in this bend of the path.");
set_items(([
({"ground", "path"}) : "The ground contains a pathway which is made of polished onyx, leading toward the throne, or back toward the city.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"painting", "walls", "wall", "paintings"}) : "There are paintings of past Valsharess of the drow covering the walls.",
({"racks", "racks of armour", "racks of weapons", "rack", "armour", "weapons"}) : "There are racks of armour and weapons are full of shiny new items.",
]));
}
void reset() {
    ::reset();
    if(!present("palaceguard")){
        new(MOB"palaceguard")->move(this_object());
        new(MOB"palaceguard")->move(this_object());
}
    if(!present("drowwarrior")){
        new(MOB"drowwarrior")->move(this_object());
        new(MOB"drowwarrior")->move(this_object());
}
    if(!present("drowchild")){
        new(MOB"drowchild")->move(this_object());
}
set_exits(([ "west" : ROOMS "58.c",
"north" : ROOMS "59e.c",
"south" : ROOMS "55e.c"]));
}
