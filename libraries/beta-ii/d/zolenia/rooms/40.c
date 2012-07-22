#include <std.h>
#include <zolenia.h>
inherit ROOM;

void create() {
::create();
set_properties( ([ "light" : 1, "indoors" : 1, "cavern" : 1, "night light" : 1]) );
set_smell("default", "The smell of fresh cut arrows drifts down from the top of the walls.");
set_listen("default", "The stringing of bows chimes throughout the room.");
set_short("around the gate walls");
set_long("The climb down the gate wall leads to absolutely nothing.  The space inside of the walls is simply a barren square of land, with slabs of rocks.  There is a hole in the ground with a ladder sticking out of it.  It seems as if these Drow do not take their security jokingly.");
set_items(([
({"onyx", "path"}) : "The ground is covered in shards of onyx, yet no pathway can be seen here..",
({"wood", "footprints"}) : "Dusty bits of woodchips cover the path, and footprints can be seen.",
"ground" : "The ground is covered in bits of woodchips.",
({"air", "dust"}) : "Particles of dust can be seen floating throughout the air.",
({"rocks", "slabs"}) : "Slabs of rocks litter the ground.",
"gate" : "The walls of the gate surround you.",
"ladder" : "Scratched into the onyx wall beside the gate door, and definitely not the safest climb, it seems like it's scarier going back down.",
"hole" : "There is a fairly large hole in the ground.",
]));
set_exits(([ "down" : ROOMS "41.c",
"up" : ROOMS "22.c"]));
}
void reset() {
    ::reset();
    if(!present("tunnelguard")){
        new(MOB"tunnelguard")->move(this_object());
        new(MOB"tunnelguard")->move(this_object());
        new(MOB"tunnelguard")->move(this_object());
        new(MOB"tunnelguard")->move(this_object());
}
}
