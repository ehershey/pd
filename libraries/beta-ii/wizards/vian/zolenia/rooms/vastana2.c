#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;

void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_smell("default", "An overpowering scent of blood resonates throughout the manor.");
set_listen("default", "Household screams of torture and pain fill your ears.");
set_short("Vastana Manor");
set_long("%^BOLD%^%^RED%^The Matron Mother's room is an absolute bloodshed.  There are not very many things in this room, but there is a lot of blood.  One of the few items is a large onyx throne, covered in red velvet, and splattered with blood.  In the corner of the room, there appears to be an actual tub filled with boiling blood.");
set_items(([
({"paths", "path"}) : "Multiple paths lead to different rooms in the house.",
({"air", "dust"}) : "The air is getting thinner and full of dust.",
"drows" : "The Vastana drows are practicing their skills.",
({"blood", "bloodshed"}) : "This room is blood.  Plain and simple, there is blood EVERYWHERE.",
({"throne"}) : "The throne is very large, fitting for a very powerful sitter.",
({"tub", "corner", "boiling blood"}) : "There is a large tub filled with what appears to be boiling blood.",
]));
}
void reset() {
    ::reset();
    if(!present("vastanamatronmother")){
        new(MOB"vastanamatronmother")->move(this_object());
}
    if(!present("vastanachild")){
        new(MOB"vastanachild")->move(this_object());
}
set_exits(([ "northwest" : ROOMS "49.c"]));
}
