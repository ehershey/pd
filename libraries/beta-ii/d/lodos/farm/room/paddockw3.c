//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
set_day_long("This part of the paddock is full of fresh green grass due to the small dam. A lone bull is seen wandering around the paddock, occasionally stopping by to drink from the dam. It seems that this paddock is used for keeping the bull secure. A forest can be seen surrounding the property and birds fly in and out of it.");
set_night_long("The paddock is illuminated by the faint moonlight. This paddock appears to be empty bar for a lone bull wandering around and occasionally drinking from the dam. A dark forest can be seen surrounding the property.");
   set_items(([
                ({"gate" , "gates"}) : "The gate is old and made out of the same wood as the forest.
It is latched closed to stop the animals from getting out.",
                ({"bird" , "birds"}) : "There are many different species of birds flying in and out
of the surrounding forest.",     
           "forest"   : "The forest is full of swaying trees, and a few stumps can be seen around
the edge",
                ]));
    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");

        set_exits(([
"north" : ROOMS"paddockw1.c",
"west" : ROOMS"paddockw4.c",
"northwest" : ROOMS"paddockw2.c",
                ]));
new(OBJ"dam.c")->move(this_object());
}


void reset() {
    ::reset();
     if (children(MOB"bull.c")==({})||
     sizeof(children(MOB"bull.c"))<3)
     new(MOB "bull")->move(this_object());

}
