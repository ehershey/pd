#include <std.h>
#include <merkcaves.h>

inherit ROOM;

void create() {
   ::create();
     set_properties((["light" : 0, "indoors" : 1]));
     set_short("Inside a cave");
     set_long("Torches hang from either side of the narrow hallway, the limestone walls glistening in a multitude under the flickering light. Smooth stairs descend, spiraling around the edge of a deep hole in the earth. The bottom cannot be made out in the gloom.");
     set_exits(([
		"northeast"	: "/d/freepk/merkkerri/jungle/merkkirri/cave4.c",
		"down"		: MCROOM"stairs.c"
		]));
     set_items(([
		"walls": "The limestone walls are smooth and damp.",
		"torches" : "The torches flicker, providing little light.",
		"stairs" : "They do not appear to be a natural formation.",
		"steps"	: "The individual steps are have a smooth surface."
		]));
     set_listen("default", "The sound of watter dripping echos throughout the cave.");
}
