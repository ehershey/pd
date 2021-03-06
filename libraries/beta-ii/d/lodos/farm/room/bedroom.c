//Valleyman

#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1, ]) );
        set_short("Farmhouse");
        set_day_long("The bedroom is light and airy with sunlight streaming in through the open windows. A four poster bed sits in the middle of the room and drawers are along the walls. A grandfather clock ticks away in one corner.");
        set_night_long("The room is dimly lit from a small oil lamp burning on one of the drawers. The silver cotton net of the four poster bed glows in the light and the ticking of a grandfather clock can be heard.");

        set_items(([
"pictures" : "Pictures of family members and the husband of wife",
"bed" : "A four poster bed with curtains hanging down the side. Looks very comfortable",
({"clock", "grandfather clock"}) : "An old grandfather clock, it sits ticking in the corner.",
]));
set_listen("default", "The ticking of a clock can be heard.");
        set_exits(([
                "out" : ROOMS"house3.c",
                ]));

}
