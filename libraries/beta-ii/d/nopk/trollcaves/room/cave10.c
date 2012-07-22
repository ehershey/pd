#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The tunnel declines in the east and climbs up to the northwest. The red-yellow stone is the most common stone appearing in this section of the cavern, with the streaks of blue which frequent large bodies of it increasing in size and frequency.");
    set_smell("default", "The rancid stench of rotting meat is incredible.");
    set_listen("default", "The cavern is as silent as a tomb.");
    set_items(([
	({"stone"}) : "The stone underfoot makes a sudden switch to a red-yellow coloured stone with occasional cracks of blue streaking through it.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "There are none here."
      ]));
    set_properties(([
	"light" : -1,
	"night light" : -2,
      ]));
    set_exits(([
	"northwest" : ROOMS"cave9.c",
	"east" : ROOMS"cave11.c",
      ]));
}
