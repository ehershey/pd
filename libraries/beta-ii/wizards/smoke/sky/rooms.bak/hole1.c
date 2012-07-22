#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 1, "night light" : 0,
                "no teleport" : 1]) );
   set_short("Inside a mountain");
   set_long(
            "The cave is enormous! The walls are jagged and rough. They're"
            " extremely high and convert into a rough ceiling. A pile of "
            "straw lies on the ground in the corner. Rough etchings of "
            "unknown tribal symbols cover the walls. A ring of stones "
            "is full of ash, probably where meals are cooked.");
   set_items(([
            "cave" : "The cave is huge! It is built inside of the mountain "
                        "and is the home to a large Minotaur.",
            "walls" : "The walls are really high and jagged. They've been cut "
                 "out of the mountain. There are rough etchings carved" 
		 "into the walls.",
            "ground" : "There is a pile of straw and a ring of stones "
		 "on the ground.",
            "ashes" : "The ashes fill the ring of stones.",
            "ring" : "There are ashes in the ring of stones. ",
            "stones" : "There are ashes in the ring of stones. ",
            "straw" : "A pile of straw is probably used as a bed. It "
		 "is in the corner on the ground.",
            "pile" : "A pile of straw is probably used as a bed. It "
		 "is in the corner on the ground.",
	    "etchings" : "Unknown etchings of tribal symbols cover "
		 "the walls.",
	    "symbols" : "Unknown etchings of tribal symbols cover "
		 "the walls."
   ]));
   set_smell("default", "The smell of ash dominates the room.");
   set_exits( ([ 
        "out" :  ROOMS "13"]));
    if(!present("shaman")) new(MOB"mshaman.c")->move(this_object());
}
