#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Basement");
    set_long("This tiny room is little more then three metres across and three times that deep, although it four metres tall. Sitting up against the back wall is a large coffin, elevated on stone bricks. There are several small holes in the roof here, drilled into large slabs of rock which lead to the surface underneath the house providing fair ventilation for the room.");
    set_smell("default", "This place is musty although the air is surprisingly fresh.");
    set_listen("default", "There are not many noises here.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"coffin"}) : "How this box even fit into this room is a mystery. The lid appears to be firmly closed.",
	({"bottles", "bottle"}) : "These bottles are not labelled and are covered in dust. Many would appear to be there for a great period of time.",
      ]));
    set_exits(([
	"east" : ROOMS"devereux_basement1.c",
      ]));
}

void init() 

{
    ::init();
    add_action("open", "open");
}

int open(str)

{
    if(str != "coffin") 
    {
	return 0;
    }
    write("The lid appears to be magically sealed and does not budge.");
    return 1;
}
