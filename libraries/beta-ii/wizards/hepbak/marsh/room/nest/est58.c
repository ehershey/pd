#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":0, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A stone ramp leading up, is located here. "
         
    );
    set_items(([
        "stone" : "It's more like a slate stone, very smooth.",
        "ramp" : "It is made of stone.",
        "nest" : "It is the home of the Raknids.",
  
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"north" : NEST "est63",
"up" : NEST "nest14",
    ])  );
}
void reset() {
 ::reset();
     if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
      new(MOB"r_guard")->move(this_object());
 
    }
}
