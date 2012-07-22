#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "The path ends here before two huts, which from a "
      "distance, it looks like one." 
     
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
"northeast" : HIVE "hiv23",
"west" : HIVE "hiv18",
"southwest" : HIVE "hiv14",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    }
}
