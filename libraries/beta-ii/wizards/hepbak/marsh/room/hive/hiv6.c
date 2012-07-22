#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The torches lights up the way along the path. "
     
    );
    set_items(([
        "torches" : "It lights up the path making it "
                    "easier to see.",
        "path" : "Made of smooth stones taken from the "
                 "river bed.",
        "stones" : "It's worn smooth, from the years of "
                   "water-wear.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"northwest" : HIVE "hiv9",
"east" : HIVE "hiv7",
    ])  );
}
