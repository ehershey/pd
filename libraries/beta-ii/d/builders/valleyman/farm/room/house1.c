//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "indoors" : 1, ]));
set_short("Farmhouse");
        set_day_long("The sitting room of the farmhouse is on the smallish side, with only a few chairs scattered around the room in front of a fireplace. Off to side is a small dining table with
four chairs around it. The sunlight shines through the windows warming the room.");
        set_night_long("The sitting room is very dark at this time of night, with no lamps to give light. There is a slight glow from the fire place as the nights embers cool. The silence is broken
by the sounds of insects outside. The moonlight shines through the windows.");

        set_items(([
"fireplace" : "The fireplace is constantly full of ashes and dying embers",
                ("dining table" , "table")   : "The dining table is made out of the same wood as the forest outside",
                ]));


        set_exits(([
"out" : ROOMS"yard1.c",
"north" : ROOMS"house2.c",
                ]));
}
void reset() {
::reset();
if(!present("man")) {
new(MOB"man.c")->move(this_object());
}
}
