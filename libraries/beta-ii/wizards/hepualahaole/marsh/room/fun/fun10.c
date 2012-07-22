#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Ogre's Paradise");
    set_long(
      "Inside the gazebo!  The flower gardens surrounds the gazebo gives "
      "the feeling of serenity. No wonder this is called Ogre's Paradise!"
    );
    set_items(([
        "cave" : "Beautiful!! Flowers everywhere, an Ogre's Paradise.",
        "flowers" : "These are flowers that need no sunlight to grow.",
        "path" : "Dirt path, dirt not from here.",
        "gazebo" : "A white one, that is in the middle of the garden.",
    ]));
    set_exits( ([
"out" : FUN "fun14",
    ]) );
}
