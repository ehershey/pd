#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 1, "night light" : 0,
                "no teleport" : 1]) );
   set_short("Red dragons den");
   set_long(
            "%^BOLD%^%^RED%^The cave is enormous! The walls are jagged and plain. They're "
            "extremely high and convert into a rough ceiling. This is the "
            "den of a small dragon family. There is a fire burning in a ring "
            "of stones, providing a little light and warmth. Egg shells are "
            "scattered about as well.%^RESET%^");
   set_items(([
            "cave" : "The cave is huge! It is built inside of the mountain "
                        "and is the home to a small dragon family.",
            "walls" : "The walls are really high and jagged. They've been cut "
                 "out of the mountain.",
            "ground" : "There are some bones littered across the ground.",
            "fire" : "The fire is burning in a ring of stones. ",
            "ring" : "The fire is burning in a ring of stones. ",
            "stones" : "The fire is burning in a ring of stones. ",
            "shells" : "Broken egg shells are discarded throughout the cave.",
   ]));
   set_smell("default", "The stench of rotten meat lingers about.");
   set_exits( ([ 
        "out" :  ROOMS "6"]));
    if(!present("dragon")) new(MOB"f_red.c")->move(this_object());
    if(!present("dragon 2")) new(MOB"m_red2.c")->move(this_object());
    if(!present("dragon 3")) new(MOB"m_red2.c")->move(this_object());
}
