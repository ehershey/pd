//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
        set_day_long("The paddock is large and full of green grass, which several cows are grazing off around the paddock. A glimmer of water can be seen to the east and a forest can be seen in all directions. The paddock continues on to the north and east and a gate can be seen to the north. What looks to be a dam can be see to the east.");
        set_night_long("The paddock is illuminated by the moonlight and the moons reflection can be seen on a water hole to the east. A gate is to the north leading out and the paddock continues to the south and east.");

        set_items(([
                ({"gate" , "gates"}) : "What looks to be and exit out of the paddock, the gate looks old and neglected.",
                "forest"   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
                ]));
    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");
        set_exits(([
"north" : ROOMS"paddocke1.c",
"east" : ROOMS"paddocke4.c",
"northeast" : ROOMS"paddocke2.c",
                ]));

}
void reset() {
::reset();
if(!present("cow")) {
new(MOB"cow.c")->move(this_object());
new(MOB"cow.c")->move(this_object());
new(MOB"chicken.c")->move(this_object());
new(MOB"chicken.c")->move(this_object());
}
}

