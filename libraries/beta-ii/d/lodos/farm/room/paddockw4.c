//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
set_day_long("The paddock is empty bar a lone bull wandering around and stopping by to drink from a dam to the east. This paddock looks like it is used only for keeping the bull away from the cows. A forest can be seen surrounding the property and differnet birds fly in and out of the trees.");
set_night_long("The paddock is illuminated by the moon and it looks empty bar from a lone bull wandering around drinking from a small dam to the east. A dark forest can be seen surrounding the property and night creatures rustle in the grass.");
     
   set_items(([
                ({"gate" , "gates"}) : "The gate is old and made out of the same wood as the forest. It is latched closed to stop the animals from getting out.",
                ({"bird" , "birds"}) : "There are many different species of birds flying in and out of the surrounding forest.",     
           "forest"   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
                ]));

    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");

        set_exits(([
"east" : ROOMS"paddockw3.c",
"north" : ROOMS"paddockw2.c",
"northeast" : ROOMS"paddockw1.c",
                ]));
}
