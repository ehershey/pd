//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
        set_day_long("A large yard covered in fresh green grass. A large farmhouse looms up in front of you, its windows open and the sounds and smell of a working kitchen hang in the air. Various animals wander around the yard, basking in the sun, or chasing each other around. A forest can be seen all around you, except for the cleared farm area surrounding the place.");
        set_night_long("The moon hangs in the sky casting is light over the land and illuninating the front of the house in front of you. Soft light can be seen through one of the windows and the sounds of pots and pans clanging can be heard. In the distance a cow mooes and various other noises of the night follow.");

        set_items(([
    ({"house", "farmhouse", "farm house"}) : "The house is painted red and white, with open windows.",
                ("forest")   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
         ({"window", "windows"}) : "The windows are open and light can be seen streaming from them.",
      ]));
        set_exits(([
"enter" : ROOMS"house1.c",
"south" : ROOMS"yard2.c",
                ]));

}
void reset() {
::reset();
if(!present("cow")) {
new(MOB"cow.c")->move(this_object());   
}
if(!present("pig")) {
new(MOB"pig.c")->move(this_object());
new(MOB"pig.c")->move(this_object());
}
}
