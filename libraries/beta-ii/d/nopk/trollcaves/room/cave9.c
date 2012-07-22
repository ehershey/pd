#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("The tunnel splits into two equally small passages, one dipping down to the southwest and the other climbing up to the southeast, with the main tunnel retreating up to the north. The ground and patches of the walls here is of a variety of stone not present in the upper levels; a dull, yellow-red which occasionally has veins of a blue crystaline substance running through it.");
    set_smell("default", "The repugnant stench of rotting meat overpowers your olfactory senses.");
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
	"north" : ROOMS"cave8.c",
	"southeast" : ROOMS"cave10.c",
	"southwest" : ROOMS"jail1.c",
      ]));
}
