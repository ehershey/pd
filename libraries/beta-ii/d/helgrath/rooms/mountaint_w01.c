#include <std.h>
#include <helgrath.h>

inherit ROOM;

void create() {
    ::create();
    set_properties(([
      "light" : 2,
      "indoors" : 1
    ]));
    set_short("Mountain Pass");
    set_long("This small alcove shelters you somewhat from the fierce winds, but the bite of the cold "
      "still seeps through your bones. High cliffs surround you on "
      "every side, except to the east where a path leads out to a clearing atop the mountain. "
      "The mouth of a dark cave gapes open to the north. "

    );
    set_exits(([ "north": ROOMS "cave01.c", 
      "east": ROOMS "mountain01.c" ]));
    set_smell("default", "It is too cold to smell anything.");
    set_listen("default", "A faint dripping noise can barely be made out.");
}
