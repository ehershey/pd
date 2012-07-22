// by Halo for Illuminati
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
::create();
    set_short("Study");
    set_long("Immediately upon entering you can feel something. This room "
"gets things done. Every available gap is filled with every "
"and any type of book you could possibly imagine. The floor is "
"covered with thick lush carpet while the roof is covered in a "
"brilliant mosaic of some long forgotten event. A massive "
"window occupies the entire backwall of the room, overlooking the great city of "
"Tirun. The desk occupies quite a large portion of the room, little of the "
"surface can be seen underneath the near solid layer of paperwork. There is only "
"one chair, obviously you are expected to stand.");
    set_items(([
        "chair" : "Covered in leather and high backed. That chair looks mighty comfy.",
        "window" : "The view from this vantage point is truly breathtaking.",
    ]));
    set_properties(([
        "indoors" : 1,
        "light" : 2,
    ]));
    set_exits(([
        "west" : ROOMS"illuminati/new/halo.c",
    ]));

}
void reset() {
::reset();      
        if(!present ("desk"))
        new(ROOMS"illuminati/new/desk.c")->move(this_object());
}
