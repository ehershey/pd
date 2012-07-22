//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
        set_day_long("The trail heads off west towards a small hill with a farmhouse on it, and a gate to a paddock is in to the south. Forest can be seen in all other directions and the trees sway in a slight breeze. The paddock is full of fresh %^GREEN%^green%^RESET%^ grass and there are several cows grazing. A slight wind buffers you and the hiss of the trees leaves can be heard among the mooing of the cows.");
        set_night_long("The hissing of the trees in the wind breaks the night silence. A paddock lit up with moonlight can be seen to the south and a large house like shape can be seen to the north-west. The trail continues off to the west towards a gate.");

        set_items(([
		"gate" : "The gate is old and made out of the same wood as the forest. It is latched closed to stop the animals from getting out.",
		"forest"   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
                ]));
    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");
        set_exits(([
"south" : ROOMS"paddocke1.c",
"west" : ROOMS"yard2.c",
                ]));

}
