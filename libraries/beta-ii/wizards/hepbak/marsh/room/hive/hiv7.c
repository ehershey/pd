#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The path splits up.  Looking westward, there is a lot "
      "of construction going on.  Eastward and northward, there "
      "are huts along the path."
     
    );
    set_items(([
        "westward" : "You can't make out what the heck is going on.",
        "eastward" : "A hut or two along the path, it's hard to make "
                     "out the outlines from here.",
        "northward" : "A hut or two along the path, it's hard to make "
                     "out the outlines from here.",
        "huts" : "It is shelter, you can't see what it is made of from "
                 "here.",
        "path" : "There are torches along the sides of the path, which "
                 "is made from smoothed stones taken from the river bed.",
        "torches" : "Provides light in which you can see.",
        "stones" : "Taken from the river-bed, it's is very smoothed from "
                   "years of water-wear.",
  
    ]));
    set_exits( ([
"north" : HIVE "hiv10",
"east" : HIVE "hiv8",
"west" : HIVE "hiv6",
"south" : HIVE "hiv5",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"r_guard")->move(this_object());
    }
}
