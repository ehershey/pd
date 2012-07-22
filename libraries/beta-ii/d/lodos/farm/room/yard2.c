//Valleyman
#include <std.h>
#include <farm.h>
inherit ROOM;

void create() {
room::create();

        set_properties( ([ "light" : 2, "night light" : 1, "forest" : 1, ]));
set_short("Farm");
        set_day_long("A path goes off to the east and west of here, to some gates leading into the paddocks, and continues west towards the forest. A fence is to the north surrounding a farmhouse on a small hill. The paddocks are large and full of farm animals grazing on the rich grass. A forest can be seen in the distance, full of swaying trees.");
        set_night_long("In the darkness you see a small trail leading off to the east and west, and what looks to be a large farmhouse sits on a small hill to the north. The sounds of farm animals and night time creatures can be heard.");

        set_items(([
		"house" : "The house is painted red and white, with open windows",
		"forest"   : "The forest is full of swaying trees, and a few stumps can be seen around the edge",
             ({"animals", "farm animals"}) : "There are many different animals here, mainly cows and pigs.",
       ]));
    set_listen("default", "The sound of trees leaves rustling in the wind can be heard.");
        set_exits(([
"north" : ROOMS"yard1.c",
"northeast" : ROOMS"pathe.c",
"northwest" : ROOMS"pathw.c",
"south" : "/d/lodos/etown7"
                ]));

}
