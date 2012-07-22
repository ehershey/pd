#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "cavern" : 1, "night light" : 2]) );
set_smell("default", "Throughout all of the smells of the city, an earthy smell overpowers most everything else.");
set_listen("default", "The murmurs of enchantments can be heard.");
set_short("The Acadmey of Zolenia");
set_long("%^BOLD%^%^BLACK%^The school of sorcere's dormitory is empty of students, all whom are busy practicing their magics.  The dormitory is a long room with bunks lining the walls, all very clean and tidy.  There is a nightstand next to each bunk, with a chest at the foot of it.  Paintings of the Valsharess and Lloth cover the walls.");
set_items(([
({"pathways", "paths"}) : "There is a pathway back to the school of Sorcere.",
({"painting", "paintings"}) : "The paintings of the Valsharess and Lloth are very intricate, definitely works that took a long time.",
({"bunk", "bunks"}) : "The bunks are all made perfectly, some have bloodstains on the sheets from training sorcerers who did not follow what they were told.",
({"nightstand"}) : "The nightstands all have the same contents on top:  a lantern, a statuette of Lloth, and textbooks.",
({"chest"}) : "A small chest at the foot of the bed is the only place that students have for their possessions..",
]));
}
void reset() {
    ::reset();
    if(!present("drowmaid")){
        new(MOB"drowmaid")->move(this_object());
}
set_exits(([ "out" : ROOMS "sorcere.c"]));}
