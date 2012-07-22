#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Graveyard");
    set_long("This area of the graveyard is mostly empty and has been reserved in case of plague, natural disaster, war or any other calamity. This ensures that the city can quickly bury those who die in such circumstances without creating a health risk to the rest of the city.");
    set_smell("default", "It smells of overturned earth.");
    set_listen("default", "As quiet as a grave.");

    set_items(([
	({"graves"}) : "These graves are mostly empty.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"west" : ROOMS"grave3.c",
      ]));
}
