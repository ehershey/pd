#include <std.h>
#include <venenum.h>
inherit ROOM;

int closed=1;

void create() {
    ::create();
    set_short("Basement");
    set_long("This small room would appear to be a wine cellar. Neat holes have been drilled into the wall here, providing a rack to store bottles of fine wines. Many of the holes are empty but there are plenty which are not. The majority of the bottles are not labeled, giving the impression that the owner of the cellar probably makes his or her own wine or buys it directly from someone who does. There are several small holes in the roof here, drilled into large slabs of rock which lead to the surface underneath the house providing fair ventilation for the room.");
    set_smell("default", "This place is musty although the air is surprisingly fresh.");
    set_listen("default", "There are not many noises here.");
    set_properties(([
	"light" : 2,
	"night light" : 1,
      ]));
    set_items(([
	({"holes"}) : "The holes in the wall are the right size for a bottle of wine. The holes in the roof are smaller, about the size of a human babie's little finger.",
	({"bottles", "bottle"}) : "These bottles are not labelled and are covered in dust. Many would appear to have been here for a great period of time.",
      ]));
    set_exits(([
	"west" : ROOMS"devereux_basement1.c",
      ]));
}
