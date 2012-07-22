#include <std.h>
#include <dragonevent.h>

inherit ROOM;

void create() {
  ::create();
  set_properties((["light" : 2, "night light" : 1, "no teleport" : 1, "mountain" : 1 ]));
  set_short("The Great Northern Ridge");
  set_long("The Great Northern Ridge\nThis is the furthest east point alonge the great northern ridge. The ridge runs east and west. The ridge physically connects all of the inner high mountain paths to one another, and symbolically connects each of the four dragon races to one another. "
    +"To the north, the mountain peak that looms in from the northeast sinks slowly into the ground, where it becomes even with the level of the great ridge to the northwest. The top of the mountain peak to the northwest gives way to a deep tunnel that gradually yet firmly sinks into the mountain's core, forming a wide, sturdy tunnel. The mountain ridge connects to a path to the southeast, which skirts the side of a small plateau. To the south, the mountain ridge drops off into a tremendously deep chasm.");
  set_exits( ([
    "northwest" : DRAG_ROOMS"dragnorth21.c",
    "west" : DRAG_ROOMS"dragnorth25.c",
    "east" : DRAG_ROOMS"dragnorth27.c",
    "southeast" : DRAG_ROOMS"chasmside",
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
