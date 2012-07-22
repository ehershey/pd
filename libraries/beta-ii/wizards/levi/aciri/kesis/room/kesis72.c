#include <std.h>
#include <kesis.h>
inherit ROOM;

void create() {
::create();
    set_short("The Main Gate");
    set_long("The Main Gate Entrance to Kesis cannot rightly be described as anything short of remarkable.  A testament to the architectural prowess of the mortal races, this gateway towers up into the air approximately fifty meters.  It appears to be composed of some unusual marble-like substance which is green except for an orange tinge at its edges.  The blocks of marble fit into each other like some three dimensional puzzle of tens of thousands of pieces and the visible surfaces of each piece are decorated with golden characters of exotic form.  The gate door is modeled in the form of an opening tortoise shell, and boldly advertises the insignia of the city, which is, strangely enough, made of shimmering tree bark.");
    
    set_items(([
             "gate" : "The massive gate is intricately composed of three dimensional, puzzle-like parts, with massive green doors that together look like a tortoise shell.",
              "door" : "The door is modeled in the form of a tortoise shell.  This probably adds to its durability against attack.",
    ]));
    set_properties(([
        "light" : 1,
        "night light" : 1,
	"town" : 1,
    ]));
    new(ITEM "gateway.c")->move (this_object());
    set_exits(([
        "west" : ROOMS "kesis71.c",
        "east" : ROOMS "kesis73.c",
    ]));
}

