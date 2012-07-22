//Valleyman

#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1, ]));
set_short("Farmhouse");
        set_day_long("The kitchen is full of pots and pans hanging from the roof beams, and ovens cover the walls making it look like a bakery. A goodwife bustles about the kitchen making different kinds of food for her husband and is covered in flour. The sitting room is to the south and a hallway extends to the east. Sunlight streams in through and open window and the sound of birds chirping can be heard over the din of the kitchen.");
        set_night_long("The kitchen is warm and slightly illuminated from the embers in the oven and pots and pans clank against each other in the slight wind coming through the open window. Moonlight gives the kitchen an etheral glow and casts shadows around the room. Pots and pans softly clank against each other breaking the night time silence.");

        set_items(([
                ({"oven" , "ovens"}) : "The ovens are still warm to the touch and are full of dying embers from the days cooking",
                ({"pots" , "pans"})  : "Pots and pans hang from the roof for storage and clank in the slight wind.",
     ]));

        set_exits(([
"south" : ROOMS"house1.c",
"east" : ROOMS"house3.c",
                ]));
}

void reset() {
::reset();
if(!present("wife")) {
new(MOB"wife.c")->move(this_object());
}
}
