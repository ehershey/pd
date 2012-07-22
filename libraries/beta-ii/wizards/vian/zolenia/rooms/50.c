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
set_long("%^BOLD%^%^YELLOW%^The Talabune manor is completely covered in faerie fire.  The members of the house can be seen striking matches and playing with gasoline.  There is a table with a crystal ball sitting in the center of the main room, completely covered in magical flames.  There are pathways lined in actual fire leading to different parts of the house.");
set_items(([
({"pathway", "pathways", "paths", "path"}) : "Pathways lined in flames lead to different parts of the house.",
({"table", "ball", "crystal ball"}) : "There is a table in the center of the room, covered completely in magical flames, with a crystal ball sitting on top.",
({"fire", "flames", "flame", "faerie fire", "magical fire"}) : "The entire manor is completely covered in real and magical flame.",
({"matches", "gasoline"}) : "Matches and gasoline can be seen all over the manor.",
]));
}
void reset() {
    ::reset();
    if(!present("talabunemother")){
        new(MOB"talabunemother")->move(this_object());
}
    if(!present("talabunemale")){
        new(MOB"talabunemale")->move(this_object());
}
    if(!present("talabunechild")){
        new(MOB"talabunechild")->move(this_object());
        new(MOB"talabunechild")->move(this_object());
        new(MOB"talabunechild")->move(this_object());
}
set_exits(([ "southeast" : ROOMS "talabune2.c",
"out" : ROOMS "47.c",
"southwest" : ROOMS "talabune3.c"]));
}
