#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The barracks are very still and quiet.");
set_short("The Acadmey of Zolenia");
set_long("%^BOLD%^%^BLACK%^The barracks are a very large and empty room.  There are messy bunks of unmade beds lining the walls, and a few random racks of armour and weapons that have been picked fairly clean.  There are paintings of the Valsharess and Lloth hung on the walls, but besides that, not many distractions in this room..");
set_items(([
({"pathways", "paths"}) : "There is a pathway back to the school of War.",
({"painting", "paintings"}) : "The paintings of the Valsharess and Lloth are very intricate, definitely works that took a long time.",
({"bunk", "bunks"}) : "There are many messy unmade bunks lining the walls, stained with blood from battle.",
]));
}
void reset() {
    ::reset();
    if(!present("drowmaid")){
        new(MOB"drowmaid")->move(this_object());
}
set_exits(([ "out" : ROOMS "barracks.c"]));}
