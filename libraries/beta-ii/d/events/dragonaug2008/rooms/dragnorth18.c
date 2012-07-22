#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("Dragon Lands North");
  set_long("The steeply slanted mountain-side path climbs further up the mountain peak to the south, where it surmounds and disappears over the top of it. The path leans dangerously outwards, threatening to dump any who may be foolish enough to traverse it down the side of the mountain peak and ultimately to their demise within the deep crevace below. The path clings dangerously to the side of the mountain peak as it makes its way to the northwest, where it disappears below around a bend in the mountain.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth13.c",
    "southeast" : DRAG_ROOMS"dragnorth22.c",
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
