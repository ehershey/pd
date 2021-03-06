#include <std.h>
#include <diran.h>

inherit ROOM;
void create() {
    ::create();
    set_properties( ([ "indoors" : 1, "light" : 2, "night light" : 1, ]) );
    set_short( "the Duergar city" );
    set_long("The road leading through the Duergar city is dark and uninviting.  Flashes of light from burning torches can be seen in the distance, but the road is usually traveled on memory or with a carried lightsource.  Housing compounds appear to be to the north and south.");
set_exits(([ "east" : ROOMS"duergar/29",
"west" : ROOMS"duergar/27",
"north" : ROOMS"duergar/31",
"south" : ROOMS"duergar/33",

]));
    set_items( ([
"torches":"Light can be seen from torches burning in the distance.",
"road":"The road is made from flat black stones.",
]) );
    set_smell("default",  "The smell of smoke is a bit overpowering.");
    set_listen("default", "There is quite a lot of noise echoing from the inside of the cave.");
if(random(100) < DIRAN_ROOM_CHANCE){
        if(!present("dwoman"))
          new(MOB "dwoman")->move(this_object());
        if(!present("dman"))
          new(MOB "dman")->move(this_object());
        if(!present("dchild"))
          new(MOB "dchild")->move(this_object());

}
}