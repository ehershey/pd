#include <std.h>
#include <fenton.h>
inherit ROOM;

void create() {
room::create();
   set_properties( ([ "light" : 2, "indoors" : 0]) );
set_property("plain",1);
    set_short("old destroyed road");
    set_long(
      "The tree is now to your southeast.  Off to the northeast "
      "lies a path to Fenton Square.  Westward you notice a dark alley. "
      "Before you stands an unarmed bandit.  He waits for the unlucky "
      "adventurer to walk by unsuspectingly."
    );
    set_items(([
        "tree" : "You don't know why but it grabs your attention.",
        "alley" : "Pitch black comes from the west.",
    ]));
    set_smell("default", "The smell of death surrounds you.");
    set_listen("default", "You hear the howl of a wolf in the distance. ");
    set_exits( ([ 
        "south" :  ROOMS"room3.c",
        "northeast" : ROOMS"room6.c",
        "west" : ROOMS"room7.c",
         ]) );
}
void reset() {
::reset();
    if(!present("bandit.c"))
      new(MOB"bandit.c")->move(this_object());
}
