#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
    ::create();
    set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
    set_short("Dragon Lands North");
    set_long("The mountain path widens out, and in then split in two by a mountain peak which rises out of the middle of the path. The path segments to the south and southeast firmly yet loosely skirting the peak, bringing the path segments close to the side of the peak yet allowing a good amount of space for large animals to travel through without incident. The mountain rises gently higher to the south, and slopes down and out of view to the north. The crevasses on both sides of the path grow steadier deeper, with the ocean below on the west and nothing but rocks and mountainsides to east. Far to the east across the deep crevice below can be seen another mountain peak with its own mountain path skirting both sides of it.");
    set_exits( ([
	"northwest" : DRAG_ROOMS"dragnorth08.c",
	"south" : DRAG_ROOMS"dragnorth14.c",
	"southeast" : DRAG_ROOMS"dragnorth15.c",
      ]) );
    set_items( ([
      ]) );
}

void reset() {
    ::reset();
    if(!present("dragon"))
	new(DRAG_MOBS"dragon.c")->move(this_object());
}
