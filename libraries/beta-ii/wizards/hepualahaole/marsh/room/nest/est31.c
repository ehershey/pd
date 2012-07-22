#include <std.h>
#include <marsh.h>
inherit ROOM;
void create() {
room::create();
    set_properties( (["light":1, "indoors":1, "cave":1]) );
    set_short("Raknid's Nest");
    set_long(
      "A single torch mounted on the wall, lights up the intersection "
      "of rooms."
         
    );
    set_items(([
        "rooms" : "Thee rooms connect to the end of this tunnel.",
        "intersection" : "Three tunnels joining together.",
        "wall" : "There is a torch mounted on a wall.",
        "light" : "It's not very bright, just enough to light the "
                  "intersection of rooms.",
        "tunnel" : "The tunnel ends, and splits up into three rooms.",
    ]));
    set_listen("default", "Sounds of chattering insects.");
    set_exits( ([
"west" : NEST "est30",
"southeast" : NEST "est22",
"northwest" : NEST "est35",
    ])  );
}
void reset() {
 ::reset();
   if (!present("torch", this_object()))
     new( ITEMS "torch.c" )->move(this_object());
    if (!present("raknid")) {
      new(MOB"r_guard")->move(this_object());
 
    }
}
