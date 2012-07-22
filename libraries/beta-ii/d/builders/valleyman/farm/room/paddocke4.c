//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
        set_day_long("This part of the paddock is crowded with cows trying to drink from the dam. The rest of the paddock stretches off to west and north with a large forest to the south and east. There are a few low growing shrubs here, drawing water from the dam.");
set_night_long("The moonlight reflects off the dam, and many cows try to drink from it at the same time, crowding the area. The paddock continues from the west to the north, with forest surrounding the entire farmland.");
        set_items(([
                "forest"   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
		({"shurbs", "shrubery"}) : "Low growing shrubs, probably drawing water from the dam.",
                ]));

        set_exits(([
"north" : ROOMS"paddocke2.c",
"west" : ROOMS"paddocke3.c",
"northwest" : ROOMS"paddocke1.c",
                ]));
    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");
}
void reset() {
::reset();
if(!present("cow")) {
new(MOB"cow.c")->move(this_object());
new(MOB"cow.c")->move(this_object());
new(MOB"cow.c")->move(this_object());
new(MOB"cow.c")->move(this_object());
new(MOB"chicken.c")->move(this_object());
new(MOB"chicken.c")->move(this_object());
new(OBJ"dam.c")->move(this_object());
}
}

