#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 1, "night light" : 0,
                "no teleport" : 1]) );
   set_short("Black dragons den");
   set_long(
            "%^BOLD%^%^BLACK%^The cave is enormous! The walls are jagged and plain. They're "
            "extremely high and convert into a rough ceiling. This is the "
            "den of a small dragon family. The only thing on the cold, stone "
            "ground are discarded bones of past meals.%^RESET%^");
   set_items(([
            "cave" : "The cave is huge! It is built inside of the mountain "
                        "and is the home to a small dragon family.",
            "walls" : "The walls are really high and jagged. They've been cut "
                 "out of the mountain.",
            "ground" : "There are some bones littered across the ground.",
            "bones" : "It is hard to tell what kind of animal this was. What"
                "ever it was made a good sized meal for a family of dragons."
   ]));
   set_smell("default", "The stench of rotten meat lingers about.");
   set_exits( ([ 
        "out" :  ROOMS "3"]));
    if(!present("dragon")) new(MOB"f_black.c")->move(this_object());
    if(!present("dragon 2")) new(MOB"m_black2.c")->move(this_object());
    if(!present("dragon 3")) new(MOB"m_black2.c")->move(this_object());
}
