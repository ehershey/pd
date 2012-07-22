//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
        set_day_long("There are no animals in this part of the paddock due to a cows carcass in the corner. The grass around the carcass is brown and dying, unlike the rest of the grass which is soft and green. A gate can be seen to the west and the paddock stretches out to the south and southwest. Forest surrounds the farm and a water hole can be seen to the south.");
        set_night_long("This part of the paddock smells like decay and the moonlight shows a large object laying in the corner. The rest of the paddock stretches off to the south and southwest whilst a gate can be seen to the west. Moonlight reflects off a water hole to the south.");

        set_items(([
                ({"gate", "gates"}) : "The gate is old and made out of the same wood as the forest. It is latched closed to stop the animals from getting out.",
                "forest"   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
]));
   set_smell("default", "The smell of a rotting corpse is here.");
    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");
        set_exits(([
"west" : ROOMS"paddocke1.c",
"southwest" : ROOMS"paddocke3.c",
"south" : ROOMS"paddocke4.c",
                ]));

}
void reset() {
::reset();
if(!present("carcass")) {
new(OBJ"carcass.c")->move(this_object());
}
}
