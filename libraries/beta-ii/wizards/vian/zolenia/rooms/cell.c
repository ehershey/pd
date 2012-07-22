#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2, "no bump" : 1, "no attack" : 1, "no magic" : 1 ]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The clangs of swords clashing with each other can be heard from outside of the cell..");
set_short("The Jail of Zolenia");
set_long("%^BOLD%^%^BLACK%^The large jail cell is guarded by the outside warriors in training as part of their duties.  It is a gigantic room with hay covering the ground, and a large metal bucket in the corner.  There are no windows, and metal bars clash against your view of the main barrack.");
set_items(([
({"warriors", "warrior"}) : "There are warriors outside in the barracks, guarding the cell.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
({"hay", "ground"}) : "The ground is covered in hay, some of which seems to be bloody.",
({"bucket", "metal bucket", "corner"}) : "There is a metal bucket in the corner of the room, which has a pungent odor emanating from within..",
({"bars"}) : "Bars cover the door to get back to the barrack.",
]));
}
void reset() {
    ::reset();
    if(!present("dwarfprisoner")){
        new(MOB"dwarfprisoner")->move(this_object());
}
set_exits(([ "out" : ROOMS "barracks.c"]));
}
