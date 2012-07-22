#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 3, "night light" : 2, "no teleport" : 1, "mountain" : 1, "coords" : ({ 138, 17, 0 }) ]));
  set_short("Dragon Lands North");
  set_long("A thick, baked-red-dirt half-inverse archway that supports a large plateau to the northwest. The inverse archway hangs out over a cataclysmically deep chasm below which, combined with the precarious nature of the archway, would breed a sense of unease in the strongest of men. Despite that, the archway is very stable and in no danger of giving out. There is a small ridge that rises out of the crook at the center of the archway and leads up to the top of the plateau to the northwest. To the east, the archway splits in two and attaches itself to the tip of the mountainside, forming a traversable path.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth39.c",
    "northeast" : DRAG_ROOMS"common7",
    "east" : DRAG_ROOMS"tradeconnect1",
             ]) );
  set_items( ([
             ]) );
}
void drag_fly(object ob) {
    ob->force_me("fly");
}

void reset() {
    object newMob;
    ::reset();
    if(sizeof(children(DRAG_MOBS"flydrag.c")) < 5) {
        newMob = new(DRAG_MOBS"flydrag.c");
        newMob->move(this_object());
        //call_out((: newMob->force_me :), 1, "fly");
        call_out((:drag_fly:), 1, newMob);
    }
}
