#include <std.h>
#include <venenum.h>
inherit VAULT;

void create() {
    ::create();
    set_short("Foyer");
    set_long("The foyer of this house is incredible, with no expense spared at decoration. This long passage is tiled with large slates of marble, polished over to give a bright shine. The walls are a plaster mix, smoothed to a fine finish by the application of skilled craftsmen. Two bronze statues stand in the doorway, depicting a pair of leopard cats about to pounce. The foyer leads to a large corridor to the north directly opposite the double doors to the south.");
    set_smell("default", "This foyer smells clean and pleasant.");
    set_listen("default", "The house is quiet and peaceful.");
    set_items(([
	({"tiles", "slate", "marble"}) : "This marble looks extremely expensive and was probably not sourced locally; it must be imported.",
	({"statue", "statues"}) : "These statues are mirror images of two great leopard cats, crouched and ready to pounce. They appear to be guarding the stairway up.",
      ]));
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_exits(([
	"north" : ROOMS"devereux3.c",
	"exit" : ROOMS"devereux1.c",
      ]));
}

