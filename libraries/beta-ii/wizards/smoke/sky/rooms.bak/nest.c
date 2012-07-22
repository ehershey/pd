#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
 ::create();
   set_properties( ([ "light" : 0, "indoors" : 0, "night light" : 0,
                "no teleport" : 1, "mountain" : 1]) );
   set_short("A birds nest");
   set_long(
            "The view from atop the cliff is amazing. Mountains stretch "
            "in all directions. A jungle reaches south and east of here. "
            "A large castle can be seen atop the mountains to the north, "
            "making this about the only spot on the island the castle "
            "is visable. A small pond sits in the middle of the jungle. "
            "The giant nest is made from tree branches, lots of mud, "
            "and huge, dried up leaves.");
   set_items(([
            "jungle" : "The jungle stretches south and east. Trees "
                        "fill the jungle with life.",
            "mountains" : "Huge mountains surround the entire island. "
                 "On top of a mountain to the north sits a huge castle.",
            "castle" : "A huge castle sits atop a mountain in the distance"
                 " off to the north. No entry way can be seen at this angle.",
            "pond" : "A small pond sits in the jungle. Swarms of insects "
                "can be seen flying all around the pond.",
            "nest" : "The nest is made from tree branches, lots of mud, "
                 "and huge, dried up leaves."
   ]));
   set_smell("default", "The air is clean and crisp.");
   set_exits( ([ 
        "down" :  ROOMS "19"]));
    if(!present("hawk")) new(MOB"hawk1.c")->move(this_object());
}
