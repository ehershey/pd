#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Ogre's Paradise");
    set_long(
      "Inside the cave is beautiful!  The gardens are full of flowers, and in "
      "the center is a white gazebo.  A dirt path leads around the garden, no "
      "wonder this is called Ogre's Paradise!"
    );
    set_items(([
        "cave" : "Beautiful!! Flowers everywhere, an Ogre's Paradise.",
        "flowers" : "These are flowers that need no sunlight to grow.",
        "path" : "Dirt path, dirt not from here.",
        "gazebo" : "A white one, that is in the middle of the garden.",
    ]));
    set_exits( ([
"northeast" : FUN "fun17",
"southeast" : FUN "fun11",
"northwest" : FUN "fun16",
"southwest" : FUN "fun9",
    ]) );
}
