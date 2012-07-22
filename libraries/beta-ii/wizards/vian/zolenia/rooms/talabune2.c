#include <std.h>
#include <zolenia.h>
inherit ROOM;
object board;
void create() {
::create();
set_properties( ([ "light" : 2, "indoors" : 1, "night light" : 2]) );
set_smell("default", "The smell of ashes and gasoline overpower all else.");
set_listen("default", "Crackling of flames and pained screams can be heard.");
set_short("Talabune Manor");
set_long("%^BOLD%^%^YELLOW%^This room is empty of anything, but a large throne which is covered in faerie fire.  The entire room is surrounded by faerie fire and real fire, save for the pathway back to the main room of the house.  Matches and gasoline litters the ground.");
set_items(([
({"pathway", "pathways", "paths", "path"}) : "A pathway lined in flames lead back to the main room of the house.",
({"throne", "chair"}) : "There is a large throne, fairly plain in appearance, covered completely in faerie fire.",
({"fire", "flames", "flame", "faerie fire", "magical fire"}) : "The entire manor is completely covered in real and magical flame.",
({"matches", "gasoline"}) : "Matches and gasoline can be seen all over the manor.",
]));
}
void reset() {
    ::reset();
    if(!present("talabunematronmother")){
        new(MOB"talabunematronmother")->move(this_object());
}
set_exits(([ "northwest" : ROOMS "50.c"]));
}
