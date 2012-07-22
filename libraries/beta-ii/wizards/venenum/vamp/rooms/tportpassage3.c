#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Deep within the Mausoleum");
    set_long("This passageway runs north and south, barely lit by some unknown light source. A faint sparkling light betrays a magical field of energy to the north and south, shimmering in the air. All four walls are nothing but set grey stone, featureless and blank.");
    set_smell("default", "The faint scent of earth is present here.");
    set_listen("default", "You can hear the distant sound of dripping water.");
    set_items(([
	({"stairways"}) : "This staircase climbs up and up, disappearing beyond your view.",
	({"field", "energy field"}) : "The field shimmers and flickers, seeming intangible.",
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
	"no teleport" : 1,
	"indoors" : 1,
	"outdoors" : 0,
      ]));
    set_exits(([
	"north" : ROOMS"tportpassage9.c",
	"south" : ROOMS"tportpassage6.c",
      ]));
}
