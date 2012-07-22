#include <std.h>
#include <sakura.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Cavern of Fangs");
    set_long("Here the cavern splits asunder; the larger part of the cavern moves to the southeast, whereas a smaller offshoot of the original cavern moves to the east. To the northwest the cavern rises up towards the entrance of the cave. The eastern deviation stands out starkly; it, unlike the upper northwestern areas and the deeper southeastern parts, is clearly artificial. Wooden bracers hold up the roughly rectangular entrance which moves off in it's own direction, slightly inclined. The trickle of water follows the natural path downwards, to the southeast. The scratch marks seem to follow the southeastern path as well.");
    set_smell("default", "The cave smells musty and dank.");
    set_listen("default", "The cavern is quiet except for the rythemic drip of water from the roof.");

    set_items(([
	({"larger"}) : "This is clearly the natural path of the cavern. It would appear that either someone attempted to bypass this with the eastern entrance, and failed, or else it has another, as yet unknown purpose.",
	({"bracers"}) : "These large wooden beams help prop up the poor quality, artificial digging.",
	({"smaller"}) : "This artificial extention to the cavern appears to be of very poor quality, and looks to be extremely hurried. The wooden support beams bearly hold up the structure. Strange enough, it slopes slightly upwards. If someone was looking to change the direction of the stream, they didn't think this through.",
	({"water", "trickle"}) : "The water preforms gravity's bidding, sloping off to the southeastern part of the cavern.",
	({"scratch marks", "marks", "scratch", "scratches"}) : "These scratch marks appear to be consistant with a large, clawed creature dragging a heavy load. They clearly lead deeper into the cavern, to the southeast."
      ]));
    set_properties(([
	"light" : 1,
	"night light" : 0,
      ]));
    set_exits(([
	"northwest" : ROOMS"cave3.c",
	"east" : ROOMS"extention1.c",
	"southeast" : ROOMS"cave5.c"
      ]));
}
