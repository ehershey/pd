//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
        set_day_long("The paddock is large and full of green grass, which several cows are grazing off around the paddock. A glimmer of water can be seen to the south and a forest can be seen in all directions. The paddock continues on to the south and east and a small gate leading out is to the north.");
        set_night_long("The paddock is illuminated by the moonlight and the sound of cows mooing mingles with the hissing of the leaves in the forest as the wind moves them. A gate is to the north leading out and the paddock continues to the south and east.");

        set_items(([
                "gate" : "The gate is old and made out of the same wood as the forest. It is latched closed to stop the animals from getting out.",
                "forest"   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
                ]));
    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");
        set_exits(([
"gate" : ROOMS"pathe.c",
"east" : ROOMS"paddocke2.c",
"south" : ROOMS"paddocke3.c",
"southeast" : ROOMS"paddocke4.c",
                ]));

}
void reset() {
::reset();
if(!present("cow")) {
new(MOB"cow.c")->move(this_object());
new(MOB"cow.c")->move(this_object());
}
}

