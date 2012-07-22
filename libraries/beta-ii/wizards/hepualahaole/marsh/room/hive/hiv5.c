#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "Torches lights up the path, making it easier to see "
      "the lush garden growing on either side of the path."
     
    );
    set_items(([
        "torches" : "It lights up the path.",
        "path" : "Made of smooth rocks taken "
                 "from the river bed.",
        "garden" : "It's mostly shrubs, it has a "
                   "healthy green glow to it.  Lack "
                   "of sun-light doesn't apper to affect "
                   "the growth to this plant.",
  
    ]));
    set_exits( ([
"north" : HIVE "hiv7",
"south" : HIVE "hiv2",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")){ 
    new(MOB"r_guard")->move(this_object());
    new(MOB"r_guard")->move(this_object());
    }
}
