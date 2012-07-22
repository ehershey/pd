#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A stone ramp leads deeper into the heart of the nest. "
      "There are two torches at the entrance, lighting the "
      "walls that are decorated with murals. "
         
    );
    set_items(([
        "ramp" : "A lot of thought went into making it, it is made "
                 "of stone and two torches sits at the entrance.",
        "torches" : "Two of them sit in front of the entrance. "
                    "They are used to light up the murals that "
                    "are on the walls.",
        "walls" : "They have murals painted on them.",
        "murals" : "Very war-like in nature, it seems to have all "
                   "the battles that were won by the Raknids.",
        "mural" : "Very war-like in nature, it seems to have all the "
                  "battles that were won by the Raknids.",
        "entrance" : "It leads to the heart of the nest.",
        "stone" : "It is more like a slate stone, very smooth.",
        "nest" : "It is the Raknid's home.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"southwest" : NEST "nest11",
"down" : NEST "est58",
    ])  );
}
void reset() {
 ::reset();
   if (!present("torch", this_object()))
     new( ITEMS "torch" )->move(this_object());
     new( ITEMS "torch" )->move(this_object());
   if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
