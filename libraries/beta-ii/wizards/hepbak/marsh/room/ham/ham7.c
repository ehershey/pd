#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
   set_properties( ([ "light" : 2]) );
    set_property("cave",1);
    set_short("Ogre Slums");
    set_long(
      "This part of the cave is known as the Ogre Slums, it's not a pretty
place to be. "
      "Trash clutters the pathway, homes are falling apart.  There is nothing
here. "
    );
    set_items(([
        "cave" : "Made of granite, making escapes impossible for Ogres.",
        "trash" : "Paper, wood, wrappers, this is no Ogre's Paradise.",
        "pathway" : "Dirt path, cluttered with trash.",
        "homes" : "Grass and stick shacks, in need of repairs.",
        "slums" : "It is unknown why they can take care of a garden and not
their homes.",
    ]));
    set_exits( ([
"northeast" : HAM "ham20",
"east" : HAM "ham8",
"west" : HAM "ham6",
    ]) );
}