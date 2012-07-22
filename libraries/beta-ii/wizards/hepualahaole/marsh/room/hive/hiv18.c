#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The home of the black widow.  Candles are placed "
      "everywhere, creating dancing shadows.  It feels "
      "creepy in here." 
     
    );
    set_items(([
        "torches" : "It lights up the path making it "
                    "easier to see.",
        "path" : "Made of smooth stones taken from the "
                 "river bed.",
        "stones" : "It's worn smooth, from the years of "
                   "water-wear.",
  
    ]));
    set_exits( ([
"east" : HIVE "hiv19",
    ])  );
}
void reset() {
 ::reset();
   if (!present("raknid")) {
      new(MOB"widow")->move(this_object());
 
    }
}
